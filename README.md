# QtExtensionPlugin
使用中间件的形式实现插件与外部使用者的通讯.各个插件内部发送pluginprotocol中提供的信号.
app通过连接pluginprotocol中的信号,从而间接实现app与plugins中的各插件进行通讯
文件结构:
app :应用程序,用于启动测试插件加载的应用程序
bin :应用程序动行的目录.里边包含运行程序,辅助库,插件库
extensionsystem: 插件管理器
pluginprotocol: 插件对外提供的接口协议库

