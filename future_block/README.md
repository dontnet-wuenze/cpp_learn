async 会创建一个 promise 对象
如果没有接收则会直接阻塞知道 future 执行析构

如果没有使用 .get 也会在析构时阻塞