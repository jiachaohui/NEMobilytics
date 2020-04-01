# iOS SDK 使用文档 #

## 接入方式

 从2.2.0之后推荐使用pod方式接入，如果仍坚持使用静态库接入的，可以联系我。

```
pod 'NEMobilytics', '~> 2.2.11'
```

## 启用 API ##

在 `*AppDelegate.m` `application:didFinishLaunchingWithOptions` 方法中调用如下方法，参数依次为 app key，版本和来源渠道。

    [[DATracker sharedTracker] startTrackerWithAppKey:@"app-key" appVersion:@"1.0" appChannel:@"AppStore"];

如需要禁用 SDK 自动上传数据功能，调用

    [[DATracker sharedTracker] startTrackerWithAppKey:@"app-key" appVersion:@"1.0" appChannel:@"AppStore" autoUpload:NO];

如需要设置只在 wifi 环境下发送数据，调用

    [[DATracker sharedTracker] startTrackerWithAppKey:@"app-key" appVersion:@"1.0" appChannel:@"AppStore" autoUpload:YES sendOnWifi:YES];

**设置为只在 WIFI 下发送数据，会导致服务器接收数据延迟，对统计系统结果的及时性会产生影响，不建议使用**

如需要使用自定义设备标识（比如 UDID），调用

    [[DATracker sharedTracker] startTrackerWithAppKey:@"app-key" appVersion:@"1.0" appChannel:@"AppStore" autoUpload:YES sendOnWifi:NO deviceUDID:@"id-set-by-app"];

**App Key 可从移动分析系统网站获取，不得使用为空值或者 null**

**以下所有调用均需发生在 `启用 API` 之后**

--------------------------

**页面自动跟踪，YES为开启，NO为关闭，默认为开**

	[[DATracker sharedTracker] setPageViewTrack:YES];

**页面过滤的白名单设置**

	此接口产品方可以配置（比如一些用到的第三方库、系统的一些自带的controller等），接口设置如下：
	
	[[DATracker sharedTracker] setFilterControllers:@[@"HTNavigationController"]];

**页面采集的自定义设置**

对于 App 中的核心页面（ViewController），提供了一个 Protocol <DAScreenAutoTracker>：

```objc
@protocol DAScreenAutoTracker
@required
//返回当前页面的Title
-(NSString *)getScreenTitle;

@optional
//自动追踪(AutoTrack)中，实现该 Protocol 的 Controller对象可以通过接口向自动采集的事件中加入属性
-(NSDictionary *)getTrackProperties;
//返回当前页面的Url,用作下个页面的referrer
-(NSString *)getScreenUrl;

@end
```

**手动发送数据请调用**

    [[DATracker sharedTracker] upload];

**设置两次数据发送的最小时间间隔，单位秒。默认定时发送为关闭状态，设置大于0的时间间隔开启定时器，否则关闭定时器**

	- (void)setUploadInterval:(NSInteger)uploadInterval;

**本地缓存的最大事件数目**

	- (void)setUploadBulkSize:(NSInteger)uploadBulkSize;

**手动禁用自动上传**

    [[DATracker sharedTracker] setAutoUploadOn:NO];

**手动开启只在 WIFI 下发送数据**

    [[DATracker sharedTracker] setSendOnWifiOn:YES];

## 远程Debug模式 ##
使用Debug可以实时远程查看上传的debug数据，便于测试同时避免debug数据写入线上数据库

开启远程调试模式，按照操作流程扫描二维码后自动开启。

用户需添加app的scheme为：**hubble.YourAppKey** 例如：hubble.MA-98E3-6F49BAA04ED7

在app激活的时候调用**[[DATracker sharedTracker] handleUrl: url ];**

```objc
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    if ([[DATracker sharedTracker] handleUrl:url]) {
        return YES;
    }
    return NO;
}
```


## 推广跟踪 ##

紧跟 `启用 API` 后调用

    [[DATracker sharedTracker] enableCampaign];

## 获取 Device ID ##

    [[DATracker sharedTracker] getDeviceId];

**该 Device ID 并非 Apple UDID, 仅用户系统本身设备去重用途, 并且可能根据 Apple 政策做相应调整, 不保证长期唯一性**

## 用户帐号管理 ##

在注册用户时，调用如下接口，统计用户注册情况

```
- (void)registerUser:(NSString*)userId;
```

在用户登录后，请调用如下接口，参数为用户帐号

    - (void)loginUser:(NSString *)userId;

当用户登出后，请调用

    - (void)logoutUser;

**如登录发生在需要捕捉事件后，则该事件无用户信息**

## 用户位置记录 ##

在拿到用户经纬度时, 调用如下接口记录用户位置

    - (void)setLocation:(double)latitude andLongitude:(double)longitude

## 事件捕捉 ##

调用如下方法进行事件捕捉

    - (void)trackEvent:(NSString *)eventId;
    - (void)trackEvent:(NSString *)eventId withAttributes:(NSDictionary *)attributes;

eventId 为事件标识，如 "login", "buy"

    [[DATracker sharedTracker] trackEvent:@"buy"];

attributes 为自定义字段名称，格式如 "{@"money":@"100", @"timestamp":@"1357872572"}"

可对事件发生时的其他信息进行记录

    [[DATracker sharedTracker] trackEvent:@"login"
        withAttributes:[NSDictionary dictionaryWithObjectsAndKeys:@"100", @"money", nil]];

还可以对事件进行归类和打标签

    - (void)trackEvent:(NSString *)eventId cagtegory:(NSString *)category label:(NSString *)label;
    - (void)trackEvent:(NSString *)eventId cagtegory:(NSString *)category label:(NSString *)label withAttributes:(NSDictionary *)attributes;

如果需要记录事件发生持续时间，可调用如下接口

    - (void)trackEvent:(NSString *)eventId costTime:(int)seconds category:(NSString *)category label:(NSString *)label;
    - (void)trackEvent:(NSString *)eventId costTime:(int)seconds category:(NSString *)category label:(NSString *)label withAttributes:(NSDictionary *)attributes;

如果需要记录事件发生时的位置信息, 可调用如下接口

    - (void)trackEvent:(NSString *)eventId costTime:(int)seconds latitude:(double)latitude longitude:(double)longitude category:(NSString *)category label:(NSString *)label withAttributes:(NSDictionary *)attributes;

**事件捕捉调用虽然可以使用在任何地方，但最好不要在较多循环内或者非主线程中调用，以及最好不要使用很长 eventID 或者 key value 值，否则会增加 SDK 发送的数据量**

## 事件自定义通用属性 ##

特别地，如果某个事件的属性，在所有事件中都会出现，可以将该属性设置为事件通用属性，通用属性会保存在 App 本地，可调用如下接口：

	- (void)registerSuperProperties:(NSDictionary *)properties;

成功设置事件通用属性后，再通过 trackEvent: 追踪事件时，事件通用属性会被添加进每个事件中。重复调用 registerSuperProperties: 会覆盖之前已设置的通用属性。

如果不覆盖之前已经设定的通用属性（除非已存在的对象值和defaultValue相等），可调用：

	- (void)registerSuperPropertiesOnce:(NSDictionary *)properties;
	- (void)registerSuperPropertiesOnce:(NSDictionary *)properties defaultValue:(id)defaultValue;

查看当前已设置的通用属性，调用：

	- (NSDictionary *)currentSuperProperties;

删除一个通用属性，调用：

	- (void)unregisterSuperProperty:(NSString *)propertyName;

删除所有已设置的事件通用属性，调用：

	- (void)clearSuperProperties;

**当事件通用属性和事件属性的 Key 冲突时，事件属性优先级最高，它会覆盖事件公共属性。**

## 事件耗时统计 ##

可以通过计时器统计事件的持续时间，默认的时间单位是毫秒。首先，在事件开始时调用 trackTimer: 记录事件开始时间，该方法并不会真正发送事件，接口为

	- (void)trackTimer:(NSString *)eventId;

调用trackEvent: 时，若已记录该事件的开始时间，SDK会在追踪相关事件时自动将事件持续时间记录在事件属性中，并删除该事件定时器。

清除所有的事件定时器，调用：

	- (void)clearTrackTimer;

多次调用 trackTimer:时，相同eventId的事件的开始时间以最后一次调用时为准。

## 异常捕捉 ##

可以在 try catch block 中进行异常捕捉，传入参数为 NSException (含子类)实例

    @try {
        [@"str" characterAtIndex:10];
    }
    @catch (NSException *exception) {
        [[DATracker sharedTracker] trackException:exception];
    }

如还需要记录 Callstack，可调用

    [[DATracker sharedTracker] trackExceptionWithCallstack:exception];

如需要手动指定异常信息，可调用

    [[DATracker sharedTracker] trackExceptionWithName:@"exception" reason:@"some reason" callstack:@"long callstack"];

## 屏幕 View 捕捉 ##

screenName 为当前 View 名称

    - (void)trackScreen:(NSString *)screenName;

## 搜索动作捕捉 ##

keyword 为搜索关键词，searchType 为搜索类型，比如新闻搜索，视频搜索等

    - (void)trackSearch:(NSString *)keyword in:(NSString *)searchType;

## 分享动作捕捉 ##

content 为分享内容，from 为分享发生地，to 为分享目的地，比如新浪微博，网易微博等

    -(void)trackShare:(NSString*)content from:(NSString *)from to:(NSString *)to;

## 用户任务记录 ##

对用户的任务进行记录，参数为任务 id 和任务失败原因，可用于用户行为完成，用户行为耗时等统计。

```objective-c
[[DATracker sharedTracker] trackOnMissionBegan:@"mission-1"];
[[DATracker sharedTracker] trackOnMissionAccomplished:@"mission-1"];
[[DATracker sharedTracker] trackOnMissionFailed:@"mission-2" reason:@"no power"];
```

## 订单统计

记录订单信息；

其中amount 为订单金额，不可为空；unit 为货币单位，采用国际通用标准，例如人民币 “CNY”，不可为空；properties 为其他自定义属性，可以为空。

```
- (void)trackOrder:(double)amount currency:(NSString*)currency properties:(NSDictionary *)properties;
```



## 打通H5和App #

为了防止 H5 不在 App 环境下浏览时，track 的事件无法通过 JavaScript SDK 发送。在初始化完 iOS SDK 之后，调用如下接口：

```objc
[[DATracker sharedTracker] addWebViewUserAgentFlag];
```

需要在WebView加载完成时，调用:

```objc
- (BOOL)showUpWebView:(id)webView request:(NSURLRequest *)request;
- (BOOL)showUpWebView:(id)webView request:(NSURLRequest *)request properties:(NSDictionary *)properties;
```

如果是UIWebView

```objc
- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType {
    NSMutableDictionary *properties = [[NSMutableDictionary alloc] init];
    [properties setValue:@"testValue" forKey:@"testKey"];
    if ([[DATracker sharedTracker] showUpWebView:webView request:request properties:properties]) {
        return NO;
    }
    
    // 在这里添加您的逻辑代码
    
    return YES;
}
```

如果是WKWebView

```objc
- (void)webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler {
    NSMutableDictionary *properties = [[NSMutableDictionary alloc] init];
    [properties setValue:@"testValue" forKey:@"testKey"];
    if ([[DATracker sharedTracker] showUpWebView:_webView request:navigationAction.request properties:properties]) {
        decisionHandler(WKNavigationActionPolicyCancel);
        return;
    }
    
    // 在这里添加您的逻辑代码

    decisionHandler(WKNavigationActionPolicyAllow);
}
```

## 设置用户属性 ##

​    为了更准确地提供针对人群的分析服务，可以使用 SDK 的 DATracker的People 设置用户属性。用户可以在留存分析、分布分析等功能中，使用用户属性作为过滤条件，精确分析特定人群的指标。

​	注意：所有的set方法都是通过内部埋点(internal_event)方式实现，所以生效机制可能有延迟。

* **获取当前用户信息设置实例**

  该对象只负责用户信息更新，每次sdk初始化时会创建该对象，但是并未与服务端同步该对象的属性，所以该对象只能用来设置属性。

	[[DATracker sharedTracker] people];

* **设置当前用户属性**

  1. **覆盖模式**

   设置多个或单个用户属性，如果有多个属性，请优先使用第一个方法批量设置。如果该属性已经设置过，会被新的属性覆盖。

	- (void)set:(NSDictionary *)profileDict; //设置多个用户属性(优先使用该方法)
	- (void)set:(NSString *) profile to:(id)content; //设置单个用户属性

* **设置用户预置属性**

系统为用户预置了几个通用的属性

```objective-c
- (void)setAccount:(NSString *)account; //尽量使用unique的字段
```

设置用户真实姓名

```objective-c
- (void)setRealName:(NSString *)realName;
```

设置用户性别(0-女，1-男，2-未知)

```objective-c
- (void)setGender:(NSInteger)gender;
```

设置用户出生日期

```objective-c
- (void)setBirthday:(NSDate *)birthday;
```

批量设置用户基本信息

```objective-c
- (void)setPopulationWithAccount:(NSString *)account realName:(NSString *)realName birthday:(NSDate *)birthday gender:(NSInteger)gender;
```

设置用户地址

```objective-c
- (void)setLocation:(NSString *)country region:(NSString *)region city:(NSString *)city;
```



* **用户属性设置示例**

```objective-c
DAPeople *people = [DATracker sharedTracker].people;
[people setPopulationWithAccount:@"test_account" realName:@"张三" birthday:[NSDate date] gender:0];
[people setLocation:@"中国" region:@"浙江省" city:@"杭州市"];
[people set:@{@"key1": @"value1", @"key2": @"value2"}];
```





## A/B测试功能 ##

如果需要A/B测试功能可以在官网上的后台中找到入口进入，然后点击添加实验按钮，选择为编程实验类型，应用类型选择iOS即可。

**只有相应试验开始运行才能在下方的这些接口中获取到变量值**

开始运行A/B测试步骤：

1. 确保试验面板中基本信息下分层的分配流量值大于0
2. 进入试验面板右上角运行控制页面，分配各个版本的分配比例
3. 点击顶部试验开始按钮

开启A/B测试功能的方法：

```objc
- (void)setABTestEnabled:(BOOL)ABEnabled;
```

同步获取本地已存的A/B测试变量方法：

```objc
- (id)getVariable:(NSString *)variableName defaultValue:(id)defaultValue;
```

异步获取服务器最新的A/B测试变量方法：

```objc
- (void)asynGetVariable:(NSString *)variableName
           defaultValue:(id)defaultValue
        timeoutInterval:(NSTimeInterval)timeout
        completionBlock:(void (^)(id variableValue, NSError *error))block;
```

**如果需需要可视化的A/B测试调试功能可以参考下方的编程试验调试文档**

## 编程试验调试 ##

如果需要进行编程调试，需要实现两步。

1. APP端先设置URL Schema，进入工程**TARGETS->Info->URL Types**输入Schema，输入格式为**hubble.APPKEY**，其中**APPKEY**部分需要替换成自己的APPKEY，可以在网站后台的**产品管理->应用管理**页面中获取，事例图如下：

    ![URL Schema](https://hubble.netease.com/help/_book/images/yingyong.png)

2. 在网页端进入具体实验，点击列表最右边的实验调试入口，进入实验调试页面，此时页面会显示二维码。打开微信或者系统相机（iOS11系统以上）扫二维码进行跳转，将会打开APP进行编程调试连接。

**连接成功以后网页端会显示当前APP的页面的实时更新截图，以及埋点数据，APP端左下角会显示一个版本浮窗按钮，点击可以进行版本切换。**

### 注意点 ###
- 连接创建以后调用DATracker的getVariable:defaultValue:方法时会优先返回调试中的版本对应的变量值
- 连接创建以后产生的埋点数据不会在本地保存以及上传到服务器保存，只是作为临时数据显示在网页端
- 连接断开以后将会恢复到原始状态
- 如果不同设备同时扫同一个二维码进入调试，所有设备的数据将会汇总到一起按时间顺序生效
- 如果同一个设备在连接状态下扫一个新的二维码将断开前一个连接
- 不同设备扫不同二维码将会各自通信，互不影响

# 无埋点

无埋点即自动埋点、全埋点，只需要app开发在初始化是启用无埋点功能，SDK会自动采集页面、控件相关的事件。

#### 启用/（关闭）方式

```
 //启用无埋点
 [[DATracker sharedTracker] enableAutoTrackConfigurationWithBlock:^(DAAutoTrackConfiguration *config) {
			// 关闭页面自动埋点，默认开启状态，包含页面进入、停留时长
            config.autoTrackScreenEvent = NO;
            // 关闭tableview点击
            config.autoTrackTabbarEvent = NO;
            //...
 }];
 //关闭无埋点
 [[DATracker sharedTracker] disableAutoTrack];
```

#### 扩展无埋点内容

暂时只提供了页面无埋点的扩展方式，可以用来覆盖eventId、添加attributes。

* 页面无埋点扩展

```
//页面无埋点扩展
@interface ABCViewController ()<DAUIViewControllerAutoTrack>
...
@end

@implementation HomeViewController
...
- (DATrackEvent*)da_screenEvent {
    return [[DATrackEvent alloc] initWithEventId:@"MyHomePage" attributes:@{}];
}

- (DATrackEvent*)da_pageDurationEvent {
    return [[DATrackEvent alloc] initWithEventId:@"MyHomePage" attributes:@{}];
}

@end
```