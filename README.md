# NetAssist - Qt 网络调试助手

NetAssist 是一个基于 **Qt** 开发的网络调试工具，支持 **TCP 客户端/服务端、UDP 通信、十六进制发送与接收、自动重连、数据统计** 等功能。  
主要用于 **物联网设备调试、协议验证、服务器通讯测试** 等场景。

---

## 🚀 功能特点

### 🔹 TCP 通信
- TCP Client 客户端模式
- TCP Server 服务端模式
- 自动重连机制
- 心跳包发送
- 连接状态监控

### 🔹 UDP 通信
- UDP 收发双向通信
- 广播/多播支持
- 多接收端口监听

### 🔹 数据处理
- HEX（十六进制）模式收发
- ASCII 模式收发
- 自动添加换行符
- 时间戳显示
- 实时流量统计

### 🔹 UI 设计
- 简洁易用的界面布局
- 多标签页功能（如已实现）
- 操作日志区 + 数据区分展示
<img width="789" height="633" alt="image" src="https://github.com/user-attachments/assets/6bdaeee7-9e56-4913-b554-f7102bdfa1a3" />

## 📦 技术栈

- **Qt 5/6**
- **QTcpSocket / QTcpServer**
- **QUdpSocket**
- **QSettings**（本地配置持久化）
- **信号槽机制**
- **多线程/异步处理**


