# iOS-SDK 更新日志
# v2.2.11

2020.4.1

* 修复设置isAutoUpload无效问题。
* 移除UIWebView的相关引用。

# v2.2.10

2020.3.23

* 统计页面时长功能默认关闭，开启需通过enableAutoTrackConfigurationWithBlock:主动打开。
* 限制单次最大上报events数量，减少服务端峰值压力。

# v2.2.9

2019.11.22

* 新增用户注册事件 registerUser 接口。

#v2.2.8

2019.8.22

* 修复网络100%loss场景下线程问题。

# v2.2.7

2019.6.26

- 新增DATracker.sessionInterval属性，开放会话间隔控制，默认仍然为15秒。
- 新增trackOrder方法，记录用户消费(供上海游戏部门使用)。
- 修复双击Home强制退出app时，session close事件未上报。
- 修复连续两次upload在间隔太短的场景下，偶尔上报的数据重复。

# v2.2.6

2019.5.27

-  修复time字段在32位机器上溢出问题。

# v2.2.5

2019.5.22

-  upload强制上传临时优化方案，保证调用upload之后不会等到下一次timer触发，前一次upload后，触发过upload会立即在上传结束时再触发一次。

# v2.2.3

2019.4.15

- 修复uploadInterval无法设置成小于15的值，同时支持云端配置uploadInterval，如果设置云端配置，本地代码设置将被忽略，建议优先使用本地设置方式。

# v2.2.0

2019.3.29：

- 新增自动埋点功能，包含了ControlEvent、手势、列表点击、页面进入&停留时长等事件采集。
- 新增运行时获取sdk版本号getSDKVersion方法，并删除了头文件静态写死版本号的注释。
- 新增运行时控制SDK日志的方法maxLogLevel和setMaxLogLevel:, 方便Debug时查看SDK本地日志。
- trackEvent方法的参数costTime变量名从seconds改成milliseconds，明确单位是毫秒。
- 提供Cocoa Pod引入方式：pod 'NEMobilytics', '~> 2.2.0'
- Bugfix: bulkSize默认值100，uploadInterval 默认值15，之前版本头文件写明了默认值但是并未设置。



# v2.1.18

2019.1.15

1) ABTest可视化实验功能初级版本，支持修改静态页面的静态控件，属性支持：文字、颜色、字体大小。

# v2.1.17

2018.12.7

1) “实时调试”功能；在生成二维码时勾选“上传日志”，则实时调试数据仍然上传，不会造成数据丢失。

2）ABTest支持实验变量一致性；在实验配置中固定实验变量后，在app使用阶段，不会因为数据同步而导致每次取到的变量不一样。

#v2.1.12

2018.10.31

1）修改SDK激活事件上送方式

#v2.1.11

2018.10.15

1）修复初始化SDK时获取ABTEST值不正确问题

#v2.1.10

2018.8.28

1）修复有时调用loginUser方法报错问题     
2）修复太多DEBUG信息打印的问题     

#v2.1.9

2018.7.24

修复设置WIFI下上传日志功能不正确问题

#v2.1.8

2018.7.4

增加A/B测试功能      
增加编程调试功能

#v2.1.4

App与H5完全打通

#v2.1.2

2017.5.12

打通H5和App，新增接口：

```
- (BOOL)showUpWebView:(id)webView request:(NSURLRequest *)request;
- (BOOL)showUpWebView:(id)webView request:(NSURLRequest *)request properties:(NSDictionary *)properties;
```

2017.6.15

发送数据服务器域名变更

#v2.1.1

2017.6.15

发送数据服务器域名变更

#v2.1

2017.5.12

打通H5和App，新增接口：

```
- (BOOL)showUpWebView:(id)webView request:(NSURLRequest *)request;
- (BOOL)showUpWebView:(id)webView request:(NSURLRequest *)request properties:(NSDictionary *)properties;
```

2017.6.12

一个多线程引起的偶现bug修复

