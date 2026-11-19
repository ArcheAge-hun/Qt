## 1. 状态转换图（主循环）

```mermaid
stateDiagram-v2
    [*] --> 红灯

    红灯: 红灯 30s<br/>最后10s闪烁
    红黄过渡: 红+黄 3s<br/>不闪
    绿灯: 绿灯 30s<br/>最后10s闪烁
    黄灯: 黄灯 3s<br/>全程闪烁

    红灯 --> 红黄过渡: finished
    红黄过渡 --> 绿灯: finished
    绿灯 --> 黄灯: finished
    黄灯 --> 红灯: finished
```



## 2. 时序图（状态机 + 三定时器协作）

```mermaid
sequenceDiagram
    autonumber
    participant SM as QStateMachine
    participant S as 当前阶段状态
    participant TT as totalTimer<br/>(单次, duration)
    participant TK as tickTimer<br/>(1s)
    participant FT as flashTimer<br/>(500ms)
    participant UI as 状态栏灯盘

    SM->>S: 进入状态 (entered)
    activate S
    S->>UI: 点亮对应灯 + 显示初始倒计时
    S->>TT: start(duration)
    S->>TK: start(1s)
    Note over S,TT: 若 duration ≤ flashLastMs<br/>则立即启动 flashTimer

    loop 每秒
        TK->>TT: remainingTime()
        TT-->>TK: 剩余毫秒
        TK->>UI: 更新倒计时(向上取整)
        alt 剩余 ≤ flashLastMs 且未闪烁
            TK->>UI: 倒计时变红高亮
            TK->>FT: start(500ms)
        end
    end

    loop 闪烁期
        FT->>UI: 整组灯同相翻转(亮/灭)
    end

    TT->>S: timeout
    S->>UI: 熄灭本阶段灯 + 清空倒计时
    S->>TK: stop()
    S->>FT: stop()
    deactivate S
    S-->>SM: 发出 finished()
    SM->>S: 进入下一状态
```

