#ifndef LEDDLL_H
#define LEDDLL_H





/*--------------------------库文件方法------------------------------*/
typedef unsigned char byte;

typedef void(__stdcall *pCallBack)(char* szMessagge, int nProgress);//回掉函数指针

/*-------------------------------------------------------------------------------
过程名:    Initialize
初始化动态库；该函数不与显示屏通讯。
DLLApp    :主程序句柄
pCallBack :返回发送的消息和进度
类型为 TCallBackFunc = procedure(szMessagge:string;nProgress:integer); stdcall;
返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pInitialize)(void* DllApp, pCallBack callBack);	//初始化动态库


/*-------------------------------------------------------------------------------
过程名:    Uninitialize
初始化动态库；该函数不与显示屏通讯。
参数:
返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pUninitialize)();	//释放动态库


/*-------------------------------------------------------------------------------
过程名:    AddScreen
向动态库中添加显示屏信息；该函数不与显示屏通讯，只用于动态库中的指定显示屏参数信息配置。
参数:
nControlType    :显示屏的控制器型号；详见宏定义“控制器型号定义”
Controller_BX_5AT = 0x0051;
Controller_BX_5A0 = 0x0151;
Controller_BX_5A1 = 0x0251;
Controller_BX_5A2 = 0x0351;
Controller_BX_5A3 = 0x0451;
Controller_BX_5A4 = 0x0551;
Controller_BX_5A1_WIFI = 0x0651;
Controller_BX_5A2_WIFI = 0x0751;
Controller_BX_5A4_WIFI = 0x0851;
Controller_BX_5A  = 0x0951;
Controller_BX_5A2_RF = 0x1351;
Controller_BX_5A4_RF = 0x1551;
Controller_BX_5AT_WIFI = 0x1651;
Controller_BX_5AL = 0x1851;

Controller_AX_AT  = 0x2051;
Controller_AX_A0  = 0x2151;

Controller_BX_5MT = 0x0552;
Controller_BX_5M1 = 0x0052;
Controller_BX_5M1X = 0x0152;
Controller_BX_5M2 = 0x0252;
Controller_BX_5M3 = 0x0352;
Controller_BX_5M4 = 0x0452;

Controller_BX_5E1 = 0x0154;
Controller_BX_5E2 = 0x0254;
Controller_BX_5E3 = 0x0354;

Controller_BX_5UT = 0x0055;
Controller_BX_5U0 = 0x0155;
Controller_BX_5U1 = 0x0255;
Controller_BX_5U2 = 0x0355;
Controller_BX_5U3 = 0x0455;
Controller_BX_5U4 = 0x0555;
Controller_BX_5U5 = 0x0655;
Controller_BX_5U  = 0x0755;
Controller_BX_5UL = 0x0855;

Controller_AX_UL  = 0x2055;
Controller_AX_UT  = 0x2155;
Controller_AX_U0  = 0x2255;
Controller_AX_U1  = 0x2355;
Controller_AX_U2  = 0x2455;

Controller_BX_5Q0 = 0x0056;
Controller_BX_5Q1 = 0x0156;
Controller_BX_5Q2 = 0x0256;
Controller_BX_5Q0P = 0x1056;
Controller_BX_5Q1P = 0x1156;
Controller_BX_5Q2P = 0x1256;
Controller_BX_5QL = 0x1356;

Controller_BX_5QS1 = 0x0157;
Controller_BX_5QS2 = 0x0257;
Controller_BX_5QS = 0x0357;
Controller_BX_5QS1P = 0x1157;
Controller_BX_5QS2P = 0x1257;
Controller_BX_5QSP = 0x1357;

Controller_BX_6E1 = $0174;
Controller_BX_6E2 = $0274;
Controller_BX_6E3 = $0374;

Controller_BX_6Q1 = $0166;
Controller_BX_6Q2 = $0266;
Controller_BX_6Q2L = $0466;
Controller_BX_6Q3 = $0366;
Controller_BX_6Q3L = $0566;
nScreenNo       :显示屏屏号；该参数与LedshowTW 2013软件中"设置屏参"模块的"屏号"参数一致。
nSendMode       :与显示屏的通讯模式；
0:串口模式、BX-5A2&RF、BX-5A4&RF等控制器为RF串口无线模式;
1:GPRS模式
2:网络模式
4:WiFi模式
5:ONBON服务器-GPRS
6:ONBON服务器-3G
nWidth          :显示屏宽度 16的整数倍；最小64；BX-5E系列最小为80
nHeight         :显示屏高度 16的整数倍；最小16；
nScreenType     :显示屏类型；1：单基色；2：双基色；
3：双基色；注意：该显示屏类型只有BX-4MC支持；同时该型号控制器不支持其它显示屏类型。
4：全彩色；注意：该显示屏类型只有BX-5Q系列支持；同时该型号控制器不支持其它显示屏类型。
5：双基色灰度；注意：该显示屏类型只有BX-5QS支持；同时该型号控制器不支持其它显示屏类型。
nPixelMode      :点阵类型；1：R+G；2：G+R；该参数只对双基色屏有效 ；默认为2；
nDataDA         :数据极性；，0x00：数据低有效，0x01：数据高有效；默认为0；
nDataOE         :OE极性；  0x00：OE 低有效；0x01：OE 高有效；默认为0；
nRowOrder       :行序模式；0：正常；1：加1行；2：减1行；默认为0；
nFreqPar        :扫描点频；0~6；默认为0；
pCom            :串口名称；串口通讯模式时有效；例:COM1
nBaud           :串口波特率：目前支持9600、57600；默认为57600；
pSocketIP       :控制卡IP地址，网络通讯模式时有效；例:192.168.0.199；
本动态库网络通讯模式时只支持固定IP模式，单机直连和网络服务器模式不支持。
nSocketPort     :控制卡网络端口；网络通讯模式时有效；例：5005
nStaticIPMode	固定IP通讯模式  0：TCP模式  ；1：UDP模式
nServerMode     :0:服务器模式未启动；1：服务器模式启动。
pBarcode        :设备条形码
pNetworkID      :服务器模式时的网络ID编号
pServerIP       :中转服务器IP地址
nServerPort     :中转服务器网络端口
pServerAccessUser:中转服务器访问用户名
pServerAccessPassword:中转服务器访问密码
pWiFiIP         :控制器WiFi模式的IP地址信息；WiFi通讯模式时有效；例:192.168.100.1
nWiFiPort       :控制卡WiFi端口；WiFi通讯模式时有效；例：5005
pGprsIP         :GPRS服务器IP地址
nGprsPort       :GPRS服务器端口
pGprsID         :GPRS编号
pScreenStatusFile:用于保存查询到的显示屏状态参数保存的INI文件名；
只有执行查询显示屏状态GetScreenStatus时，该参数才有效
返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pAddScreen)(int nControlType, int nScreenNo, int nSendMode,
	int nWidth, int nHeight, int nScreenType, int nPixelMode, int nDataDA,
	int nDataOE, int nRowOrder, int nDataFlow, int nFreqPar, char* pCom, int nBaud,
	char* pSocketIP, int nSocketPort, int nStaticIPMode, int nServerMode, char* pBarcode, char* pNetworkID,
	char* pServerIP, int nServerPort, char* pServerAccessUser, char* pServerAccessPassword,
	char* pWiFiIP, int nWiFiPort, char* pGprsIP, int nGprsPort, char* pGprsID, char* pScreenStatusFile); //添加屏显

/*-------------------------------------------------------------------------------
过程名:    DeleteScreen
删除指定显示屏信息，删除显示屏成功后会将该显示屏下所有节目信息从动态库中删除。
该函数不与显示屏通讯，只用于动态库中的指定显示屏参数信息配置。
参数:
nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}*/
typedef int(__stdcall *pDeleteScreen)(int nScreenNo);//删除屏显


/*-------------------------------------------------------------------------------
过程名:    DeleteScreen
删除指定显示屏信息，删除显示屏成功后会将该显示屏下所有节目信息从动态库中删除。
该函数不与显示屏通讯，只用于动态库中的指定显示屏参数信息配置。
参数:
nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}*/
typedef int(__stdcall *pDeleteScreen)(int nScreenNo);//删除屏显
/*-------------------------------------------------------------------------------
过程名:    SendScreenInfo
通过指定的通讯模式，发送相应信息、命令到显示屏。该函数与显示屏进行通讯
参数:
nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nSendCmd        :通讯命令值
SEND_CMD_PARAMETER =41471;  加载屏参数。
SEND_CMD_SENDALLPROGRAM = 41456;  发送所有节目信息。
SEND_CMD_POWERON =41727; 强制开机
SEND_CMD_POWEROFF = 41726; 强制关机
SEND_CMD_TIMERPOWERONOFF = 41725; 定时开关机
SEND_CMD_CANCEL_TIMERPOWERONOFF = 41724; 取消定时开关机
SEND_CMD_RESIVETIME = 41723; 校正时间。
SEND_CMD_ADJUSTLIGHT = 41722; 亮度调整。
nOtherParam1    :保留参数；0
返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pSendScreenInfo)(int nScreenNo, int nSendCmd, int nOtherParam1);//发送相应命令到显示屏。

/*-------------------------------------------------------------------------------
过程名:    AddScreenProgram
向动态库中指定显示屏添加节目；该函数不与显示屏通讯，只用于动态库中的指定显示屏节目信息配置。
参数:
nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nProgramType    :节目类型；0正常节目。
nPlayLength     :0:表示自动顺序播放；否则表示节目播放的长度；范围1~65535；单位秒
nStartYear      :节目的生命周期；开始播放时间年份。如果为无限制播放的话该参数值为65535；如2010
nStartMonth     :节目的生命周期；开始播放时间月份。如11
nStartDay       :节目的生命周期；开始播放时间日期。如26
nEndYear        :节目的生命周期；结束播放时间年份。如2011
nEndMonth       :节目的生命周期；结束播放时间月份。如11
nEndDay         :节目的生命周期；结束播放时间日期。如26
nMonPlay        :节目在生命周期内星期一是否播放;0：不播放;1：播放.
nTuesPlay       :节目在生命周期内星期二是否播放;0：不播放;1：播放.
nWedPlay        :节目在生命周期内星期二是否播放;0：不播放;1：播放.
nThursPlay      :节目在生命周期内星期二是否播放;0：不播放;1：播放.
bFriPlay        :节目在生命周期内星期二是否播放;0：不播放;1：播放.
nSatPlay        :节目在生命周期内星期二是否播放;0：不播放;1：播放.
nSunPlay        :节目在生命周期内星期二是否播放;0：不播放;1：播放.
nStartHour      :节目在当天开始播放时间小时。如8
nStartMinute    :节目在当天开始播放时间分钟。如0
nEndHour        :节目在当天结束播放时间小时。如18
nEndMinute      :节目在当天结束播放时间分钟。如0
返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pAddScreenProgram)(int nScreenNo, int nProgramType, int nPlayLength,
	int nStartYear, int nStartMonth, int nStartDay, int nEndYear, int nEndMonth, int nEndDay,
	int nMonPlay, int nTuesPlay, int nWedPlay, int nThursPlay, int bFriPlay, int nSatPlay, int nSunPlay,
	int nStartHour, int nStartMinute, int nEndHour, int nEndMinute); //向指定显示屏添加节目；

/*-------------------------------------------------------------------------------
过程名:    DeleteScreenProgram
删除指定显示屏指定节目，删除节目成功后会将该节目下所有区域信息删除。
该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目信息配置。
参数:
nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pDeleteScreenProgram)(int nScreenNo, int nProgramOrd); //删除节目

/*-------------------------------------------------------------------------------
过程名:    DeleteScreenProgramArea
删除指定显示屏指定节目的指定区域，删除区域成功后会将该区域下所有信息删除。
该函数不与显示屏通讯，只用于动态库中指定显示屏指定节目中指定的区域信息配置。
参数:
nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
nAreaOrd        :区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pDeleteScreenProgramArea)(int nScreenNo, int nProgramOrd, int nAreaOrd);//删除区域



/*-------------------------------------------------------------------------------
过程名:    QuerryServerDeviceList
查询中转服务器设备的列表信息。
该函数与显示屏进行通讯
参数:      nScreenNo, nSendMode: Integer
nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nSendMode       :与显示屏的通讯模式；
0:串口模式、BX-5A2&RF、BX-5A4&RF等控制器为RF串口无线模式;
2:网络模式;
4:WiFi模式
5:ONBON服务器-GPRS
6:ONBON服务器-3G
pDeviceList       : 保存查询的设备列表信息
将设备的信息用组成字符串, 比如：
设备1：名称 条形码 状态 类型 网络ID
设备2：名称 条形码 状态 类型 网络ID
组成字符串为：'设备1名称,设备1条形码,设备1状态,设备1类型,设备1网络ID;设备2名称,设备2条形码,设备2状态,设备2类型,设备2网络ID'
设备状态(Byte):  $10:设备未知
$11:设备在线
$12:设备不在线

设备类型(Byte): $16:设备为2G
$17:设备为3G
pDeviceCount      : 查询的设备个数

返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pQuerryServerDeviceList)(int nScreenNo, int nSendMode, byte pDeviceList[], int &nDeviceCount);

/*-------------------------------------------------------------------------------
过程名:    BindServerDevice
绑定中转服务器设备。
该函数不与显示屏进行通讯
参数:      nScreenNo, nSendMode: Integer
nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
pBarcode       :绑定设备的条形码；
pNetworkId     :绑定设备的网络ID；

返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pBindServerDevice)(int nScreenNo, char* pBarcode, char* pNetworkId);

/*-------------------------------------------------------------------------------
过程名:    SetScreenAdjustLight
设定显示屏的亮度调整参数，该函数可设置手工调亮和定时调亮两种模式。该函数不与显示屏通讯，
只用于动态库中对指定显示屏的亮度调整信息配置。如需将设定的亮度调整值发送到显示屏上，
只需使用SendScreenInfo函数发送亮度调整命令即可。
参数:
nScreenNo		:显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nAdjustType	:亮度调整类型；0：手工调亮；1：定时调亮
nHandleLight:手工调亮的亮度值，只有nAdjustType=0时该参数有效。
nHour1			:第一组定时调亮时间的小时
nMinute1		:第一组定时调亮时间的分钟
nLight1			:第一组定时调亮的亮度值
nHour2			:第二组定时调亮时间的小时
nMinute2		:第二组定时调亮时间的分钟
nLight2			:第二组定时调亮的亮度值
nHour3			:第三组定时调亮时间的小时
nMinute3		:第三组定时调亮时间的分钟
nLight3			:第三组定时调亮的亮度值
nHour4			:第四组定时调亮时间的小时
nMinute4		:第四组定时调亮时间的分钟
nLight4			:第四组定时调亮的亮度值
返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pSetScreenAdjustLight)(int nScreenNo, int nAdjustType, int nHandleLight,
	int nHour1, int nMinute1, int nLight1,
	int nHour2, int nMinute2, int nLight2,
	int nHour3, int nMinute3, int nLight3,
	int nHour4, int nMinute4, int nLight4);

/*-------------------------------------------------------------------------------
过程名:    SetScreenTimerPowerONOFF
设定显示屏的定时开关机参数，可以设置3组开关机时间。该函数不与显示屏通讯，
只用于动态库中对指定显示屏的定时开关机信息配置。如需将设定的定时开关值发送到显示屏上，
只需使用SendScreenInfo函数发送定时开关命令即可。
参数:
nScreenNo		:显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nOnHour1		:第一组定时开关的开机时间的小时
nOnMinute1	:第一组定时开关的开机时间的分钟
nOffHour1		:第一组定时开关的关机时间的小时
nOffMinute1	:第一组定时开关的关机时间的分钟
nOnHour2		:第二组定时开关的开机时间的小时
nOnMinute2	:第二组定时开关的开机时间的分钟
nOffHour2		:第二组定时开关的关机时间的小时
nOffMinute2	:第二组定时开关的关机时间的分钟
nOnHour3		:第三组定时开关的开机时间的小时
nOnMinute3	:第三组定时开关的开机时间的分钟
nOffHour3		:第三组定时开关的关机时间的小时
nOffMinute3	:第三组定时开关的关机时间的分钟
返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pSetScreenTimerPowerONOFF)(int nScreenNo,
	int nOnHour1, int nOnMinute1, int nOffHour1, int nOffMinute1,
	int nOnHour2, int nOnMinute2, int nOffHour2, int nOffMinute2,
	int nOnHour3, int nOnMinute3, int nOffHour3, int nOffMinute3);

/*-------------------------------------------------------------------------------
过程名:    GetScreenStatus
查询当前显示屏状态，将查询状态参数保存到AddScreen函数中的pScreenStatusFile的INI类型文件中。
该函数与显示屏进行通讯
参数:      nScreenNo, nSendMode: Integer
nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nSendMode       :与显示屏的通讯模式；
0:串口模式、BX-5A2&RF、BX-5A4&RF等控制器为RF串口无线模式;
2:网络模式;
4:WiFi模式
返回值            :详见返回状态代码定义。
------------------------------------------------------------------------------ * */
typedef int(__stdcall *pGetScreenStatus)(int nScreenNo, int nSendMode);

/*-------------------------------------------------------------------------------
过程名:    SaveUSBScreenInfo
保存显示屏数据信息到USB设备。方便用户用USB方式更新显示屏信息。该函数与LedshowTW软件配套的USB下载功能一致。
使用该功能时，注意当前控制器是否支持USB下载功能。
参数:      nScreenNo, bCorrectTime: nAdvanceHour,nAdvanceMinute,pUSBDisk
nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
bCorrectTime       :是否校正时间
0：不校正时间；
1：校正时间。
nAdvanceHour  :校正时间比当前计算机时间提前的小时值。范围0~23；只有当bCorrectTime=1时有效。
nAdvanceMinute    :校正时间比当前计算机时间提前的分钟值。范围0~59；只有当bCorrectTime=1时有效。
pUSBDisk  :USB设备的路径名称；格式为"盘符:\"的格式。
返回值            :详见返回状态代码定义。
------------------------------------------------------------------------------ * */
typedef int(__stdcall *pSaveUSBScreenInfo)(int nScreenNo, int bCorrectTime, int nAdvanceHour, int nAdvanceMinute, char* pUSBDisk);


/*-------------------------------------------------------------------------------
过程名:    AddScreenProgramBmpTextArea:
向动态库中指定显示屏的指定节目添加图文区域；该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中的图文区域信息配置。
参数:
nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
nX              :区域的横坐标；显示屏的左上角的横坐标为0；最小值为0
nY              :区域的纵坐标；显示屏的左上角的纵坐标为0；最小值为0
nWidth          :区域的宽度；最大值不大于显示屏宽度-nX
nHeight         :区域的高度；最大值不大于显示屏高度-nY
返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pAddScreenProgramBmpTextArea)(int nScreenNo, int nProgramOrd, int nX, int nY,
	int nWidth, int nHeight);//向指定显示屏指定节目添加图文区；


/*-------------------------------------------------------------------------------
过程名:    AddScreenProgramAreaBmpTextFile
向动态库中指定显示屏的指定节目的指定图文区域添加文件；
该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中指定图文区域的文件信息配置。
参数:
nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
nAreaOrd        :区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
pFileName       :文件名称  支持.bmp,jpg,jpeg,rtf,txt等文件类型。
nShowSingle     :单、多行显示；1：单行显示；0：多行显示；该参数只有在pFileName为txt类型文件时该参数才有效。
pFontName       :字体名称；支持当前操作系统已经安装的矢量字库；该参数只有pFileName为txt类型文件时该参数才有效。
nFontSize       :字体字号；支持当前操作系统的字号；该参数只有pFileName为txt类型文件时该参数才有效。
nBold           :字体粗体；支持1：粗体；0：正常；该参数只有pFileName为txt类型文件时该参数才有效。
nFontColor      :字体颜色；该参数只有pFileName为txt类型文件时该参数才有效。
nStunt          :显示特技。
0x00:随机显示
0x01:静态
0x02:快速打出
0x03:向左移动
0x04:向左连移
0x05:向上移动            3T类型控制卡无此特技
0x06:向上连移            3T类型控制卡无此特技
0x07:闪烁                3T类型控制卡无此特技
0x08:飘雪
0x09:冒泡
0x0A:中间移出
0x0B:左右移入
0x0C:左右交叉移入
0x0D:上下交叉移入
0x0E:画卷闭合
0x0F:画卷打开
0x10:向左拉伸
0x11:向右拉伸
0x12:向上拉伸
0x13:向下拉伸            3T类型控制卡无此特技
0x14:向左镭射
0x15:向右镭射
0x16:向上镭射
0x17:向下镭射
0x18:左右交叉拉幕
0x19:上下交叉拉幕
0x1A:分散左拉
0x1B:水平百页            3T、3A、4A、3A1、3A2、4A1、4A2、4A3、4AQ类型控制卡无此特技
0x1C:垂直百页            3T、3A、4A、3A1、3A2、4A1、4A2、4A3、4AQ、3M、4M、4M1、4MC类型控制卡无此特技
0x1D:向左拉幕            3T、3A、4A类型控制卡无此特技
0x1E:向右拉幕            3T、3A、4A类型控制卡无此特技
0x1F:向上拉幕            3T、3A、4A类型控制卡无此特技
0x20:向下拉幕            3T、3A、4A类型控制卡无此特技
0x21:左右闭合            3T类型控制卡无此特技
0x22:左右对开            3T类型控制卡无此特技
0x23:上下闭合            3T类型控制卡无此特技
0x24:上下对开            3T类型控制卡无此特技
0x25:向右连移
0x26:向右连移
0x27:向下移动            3T类型控制卡无此特技
0x28:向下连移            3T类型控制卡无此特技
nRunSpeed       :运行速度；0~63；值越大运行速度越慢。
nShowTime       :停留时间；0~65525；单位0.5秒

返回值:           :详见返回状态代码定义。
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pAddScreenProgramAreaBmpTextFile)(int nScreenNo, int nProgramOrd, int nAreaOrd,
	char* pFileName, int nShowSingle, int nHorAlign, int nVerAlign, char* pFontName, int nFontSize, int nBold, int nItalic, int nUnderline, int nFontColor,
	int nStunt, int nRunSpeed, int nShowTime, int nStretch, int nShift); //向指定显示屏指定节目指定区域添加文件

/*-------------------------------------------------------------------------------
过程名:    AddScreenProgramAreaBmpTextText
向动态库中指定显示屏的指定节目的指定图文区域添加文本；
该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中指定图文区域的文件信息配置。
参数:
nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
nAreaOrd        :区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
pFileName       :文本
nShowSingle     :单、多行显示；1：单行显示；0：多行显示；该参数只有在pFileName为txt类型文件时该参数才有效。
pFontName       :字体名称；支持当前操作系统已经安装的矢量字库；该参数只有pFileName为txt类型文件时该参数才有效。
nFontSize       :字体字号；支持当前操作系统的字号；该参数只有pFileName为txt类型文件时该参数才有效。
nBold           :字体粗体；支持1：粗体；0：正常；该参数只有pFileName为txt类型文件时该参数才有效。
nFontColor      :字体颜色；该参数只有pFileName为txt类型文件时该参数才有效。
nStunt          :显示特技。
0x00:随机显示
0x01:静态
0x02:快速打出
0x03:向左移动
0x04:向左连移
0x05:向上移动            3T类型控制卡无此特技
0x06:向上连移            3T类型控制卡无此特技
0x07:闪烁                3T类型控制卡无此特技
0x08:飘雪
0x09:冒泡
0x0A:中间移出
0x0B:左右移入
0x0C:左右交叉移入
0x0D:上下交叉移入
0x0E:画卷闭合
0x0F:画卷打开
0x10:向左拉伸
0x11:向右拉伸
0x12:向上拉伸
0x13:向下拉伸            3T类型控制卡无此特技
0x14:向左镭射
0x15:向右镭射
0x16:向上镭射
0x17:向下镭射
0x18:左右交叉拉幕
0x19:上下交叉拉幕
0x1A:分散左拉
0x1B:水平百页            3T、3A、4A、3A1、3A2、4A1、4A2、4A3、4AQ类型控制卡无此特技
0x1C:垂直百页            3T、3A、4A、3A1、3A2、4A1、4A2、4A3、4AQ、3M、4M、4M1、4MC类型控制卡无此特技
0x1D:向左拉幕            3T、3A、4A类型控制卡无此特技
0x1E:向右拉幕            3T、3A、4A类型控制卡无此特技
0x1F:向上拉幕            3T、3A、4A类型控制卡无此特技
0x20:向下拉幕            3T、3A、4A类型控制卡无此特技
0x21:左右闭合            3T类型控制卡无此特技
0x22:左右对开            3T类型控制卡无此特技
0x23:上下闭合            3T类型控制卡无此特技
0x24:上下对开            3T类型控制卡无此特技
0x25:向右连移
0x26:向右连移
0x27:向下移动            3T类型控制卡无此特技
0x28:向下连移            3T类型控制卡无此特技
nRunSpeed       :运行速度；0~63；值越大运行速度越慢。
nShowTime       :停留时间；0~65525；单位0.5秒

返回值:           :详见返回状态代码定义。
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pAddScreenProgramAreaBmpTextText)(int nScreenNo, int nProgramOrd, int nAreaOrd,
	char* pText, int nShowSingle, int nHorAlign, int  nVerAlign, char* pFontName, int nFontSize, int nBold, int nItalic, int nUnderline, int nFontColor,
	int nStunt, int nRunSpeed, int nShowTime, int nStretch, int nShift); //向指定显示屏指定节目指定区域添加文件

/*-------------------------------------------------------------------------------
过程名:    DeleteScreenProgramAreaBmpTextFile
删除指定显示屏指定节目指定图文区域的指定文件，删除文件成功后会将该文件信息删除。
该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目指定区域中的指定文件信息配置。
参数:
nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
nAreaOrd        :区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
nFileOrd        :文件序号；该序号按照文件添加顺序，从0顺序递增，如删除中间的文件，后面的文件序号自动填充。
返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pDeleteScreenProgramAreaBmpTextFile)(int nScreenNo, int nProgramOrd, int nAreaOrd, int nFileOrd); //删除指定显示屏指定节目指定图文区域的指定文件，删除文件成功后会将该文件信息删除

/*-------------------------------------------------------------------------------
过程名:    AddScreenProgramTimeArea
向动态库中指定显示屏的指定节目添加时间区域；该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中的时间区域信息配置。
参数:
nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
nX              :区域的横坐标；显示屏的左上角的横坐标为0；最小值为0
nY              :区域的纵坐标；显示屏的左上角的纵坐标为0；最小值为0
nWidth          :区域的宽度；最大值不大于显示屏宽度-nX
nHeight         :区域的高度；最大值不大于显示屏高度-nY
返回值            :详见返回状态代码定义。
-----------------------------------------------------------------------------*/
typedef int(__stdcall *pAddScreenProgramTimeArea)(int nScreenNo,
	int nProgramOrd, int nX, int nY, int nWidth, int nHeight);

/*--------------------------------------------------------------------------
过程名:    AddScreenProgramTimeAreaFile
向动态库中指定显示屏的指定节目的指定时间区域属性；该函数不与显示屏通讯，
只用于动态库中的指定显示屏指定节目中指定时间区域属性信息配置。
参数:
nScreenNo   :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nProgramOrd :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
nAreaOrd    :区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
pInputtxt   :固定文字
pFontName   :文字的字体
nSingal     :单行多行，0为单行 1为多行，单行模式下nAlign不起作用
nAlign      :文字对齐模式，对多行有效，0为左1为中2为右
nFontSize   :文字的大小
nBold       :是否加粗，0为不1为是
nItalic     :是否斜体，0为不1为是
nUnderline  :是否下滑线，0为不1为是
nUsetxt     :是否使用固定文字，0为不1为是
nTxtcolor   :固定文字颜色，传递颜色的10进制 红255 绿65280 黄65535
nUseymd     :是否使用年月日，0为不1为是
nYmdstyle   :年月日格式，详见使用说明文档的附件1
nYmdcolor   :年月日颜色，传递颜色的10进制
nUseweek    :是否使用星期，0为不1为是
nWeekstyle  :星期格式，详见使用说明文档的附件1
nWeekcolor  :星期颜色，传递颜色的10进制
nUsehns     :是否使用时分秒，0为不1是
nHnsstyle   :时分秒格式，详见使用说明文档的附件1
nHnscolor   :时分秒颜色，传递颜色的10进制
nAutoset    :是否自动设置大小对应宽度，0为不1为是（默认不使用）
返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
---------------------------------------------------------------------------------*/
typedef int(__stdcall *pAddScreenProgramTimeAreaFile)(int nScreenNo, int nProgramOrd, int nAreaOrd,
	char* pInputtxt, char* pFontName,
	int nSingal, int nAlign, int nFontSize, int nBold, int nItalic, int nUnderline,
	int nUsetxt, int nTxtcolor,
	int nUseymd, int nYmdstyle, int nYmdcolor,
	int nUseweek, int nWeekstyle, int nWeekcolor,
	int nUsehns, int nHnsstyle, int nHnscolor, int nAutoset);

/*-----------------------------------------------------------------------
过程名:    AddScreenProgramLunarArea
向动态库中指定显示屏的指定节目添加农历区域；该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中的农历区域信息配置。
参数:
nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
nX              :区域的横坐标；显示屏的左上角的横坐标为0；最小值为0
nY              :区域的纵坐标；显示屏的左上角的纵坐标为0；最小值为0
nWidth          :区域的宽度；最大值不大于显示屏宽度-nX
nHeight         :区域的高度；最大值不大于显示屏高度-nY
返回值            :详见返回状态代码定义。
---------------------------------------------------------------------------}
------------------------------------------------------------------------- * */
typedef int(__stdcall *pAddScreenProgramLunarArea)(int nScreenNo, int nProgramOrd,
	int nX, int nY, int nWidth, int nHeight);

/*-------------------------------------------------------------------------------
过程名:    AddScreenProgramLunarAreaFile
向动态库中指定显示屏的指定节目的指定农历区域属性；该函数不与显示屏通讯，
只用于动态库中的指定显示屏指定节目中指定农历区域属性信息配置。
参数:
nScreenNo		:显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nProgramOrd	:节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
nAreaOrd		:区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
pInputtxt		:固定文字
pFontName		:文字的字体
nSingal			:单行多行，0为单行 1为多行，单行模式下nAlign不起作用
nAlign			:文字对齐模式，对多行有效，0为左1为中2为右
nFontSize		:文字的大小
nBold				:是否加粗，0为不1为是
nItalic			:是否斜体，0为不1为是
nUnderline	:是否下滑线，0为不1为是
nUsetxt			:是否使用固定文字，0为不1为是
nTxtcolor		:固定文字颜色，传递颜色的10进制
nUseyear		:是否使用天干，0为不1为是  （辛卯兔年）
nYearcolor	:天干颜色，传递颜色的10进制
nUsemonth		:是否使用农历，0为不1为是  （九月三十）
nMonthcolor	:农历颜色，传递颜色的10进制
nUsesolar		:是否使用节气，0为不1是
nSolarcolor	:节气颜色，传递颜色的10进制
nAutoset		:是否自动设置大小对应宽度，0为不1为是（默认不使用）
返回值            :详见返回状态代码定义。
-----------------------------------------------------------------------}
-----------------------------------------------------------------------* */
typedef int(__stdcall *pAddScreenProgramLunarAreaFile)(int nScreenNo, int nProgramOrd, int nAreaOrd,
	char* pInputtxt, char* pFontName,
	int nSingal, int nAlign, int nFontSize, int nBold, int nItalic, int nUnderline,
	int nUsetxt, int nTxtcolor, int nUseyear, int nYearcolor, int nUsemonth, int nMonthcolor,
	int nUsesolar, int nSolarcolor, int nAutoset);
/*----------------------------------------------------------------------------
过程名:    AddScreenProgramClockArea
向动态库中指定显示屏的指定节目添加表盘区域；该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中的表盘区域信息配置。
参数:
nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
nX              :区域的横坐标；显示屏的左上角的横坐标为0；最小值为0
nY              :区域的纵坐标；显示屏的左上角的纵坐标为0；最小值为0
nWidth          :区域的宽度；最大值不大于显示屏宽度-nX
nHeight         :区域的高度；最大值不大于显示屏高度-nY
返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------}
-------------------------------------------------------------------------------* */
typedef int(__stdcall *pAddScreenProgramClockArea)(int nScreenNo, int nProgramOrd,
	int nX, int nY, int nWidth, int nHeight);

/*-------------------------------------------------------------------------
过程名:    AddScreenProgramClockAreaFile
向动态库中指定显示屏的指定节目的指定表盘区域属性；该函数不与显示屏通讯，
只用于动态库中的指定显示屏指定节目中指定表盘区域属性信息配置。
参数:
nScreenNo			:显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nProgramOrd 	:节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
nAreaOrd			:区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
nusetxt				:是否使用固定文字 0为不1为是
nusetime			:是否使用年月日时间 0为不1为是
nuseweek			:是否使用星期 0为不1为是
ntimeStyle		:年月日时间格式，参考时间区的表格说明
nWeekStyle		:星期时间格式，参考时间区的表格说明
ntxtfontsize	:固定文字的字大小
ntxtfontcolor	:固定文字的颜色；传递颜色的10进制;红255绿65280黄65535
ntxtbold			:固定文字是否加粗 0为不1为是
ntxtitalic		:固定文字是否斜体 0为不1为是
ntxtunderline	:固定文字是否下划线 0为不1为是
txtleft				:固定文字在表盘区域中的X坐标
txttop				:固定文字在表盘区域中的Y坐标
ntimefontsize	:年月日文字的字大小
ntimefontcolor:年月日文字的颜色； 传递颜色的10进制
ntimebold			:年月日文字是否加粗 0为不1为是
ntimeitalic		:年月日文字是否斜体 0为不1为是
ntimeunderline:年月日文字是否下划线 0为不1为是
timeleft			:年月日文字在表盘区域中的X坐标
timetop				:年月日文字在表盘区域中的X坐标
nweekfontsize	:星期文字的字大小
nweekfontcolor:星期文字的颜色；传递颜色的10进制
nweekbold			:星期文字是否加粗 0为不1为是
nweekitalic		:星期文字是否斜体 0为不1为是
nweekunderline:星期文字是否下划线 0为不1为是
weekleft			:星期文字在表盘区域中的X坐标
weektop				:星期文字在表盘区域中的X坐标
nclockfontsize:表盘文字的字大小
nclockfontcolor:表盘文字的颜色；传递颜色的10进制
nclockbold		:表盘文字是否加粗 0为不1为是
nclockitalic	:表盘文字是否斜体 0为不1为是
nclockunderline:表盘文字是否下划线 0为不1为是
clockcentercolor:表盘中心颜色；传递颜色的10进制
mhrdotstyle		:3/6/9时点类型 0线形1圆形2方形3数字4罗马
mhrdotsize		:3/6/9时点尺寸 0-8
mhrdotcolor		:3/6/9时点颜色；传递颜色的10进制
hrdotstyle		:3/6/9外的时点类型  0线形1圆形2方形3数字4罗马
hrdotsize			:3/6/9外的时点尺寸 0-8
hrdotcolor		:3/6/9外的时点颜色；传递颜色的10进制
mindotstyle		:分钟点类型  0线形1圆形2方形
mindotsize		:分钟点尺寸 0-1
mindotcolor		:分钟点颜色；传递颜色的10进制
hrhandsize		:时针尺寸 0-8
hrhandcolor		:时针颜色；传递颜色的10进制
minhandsize		:分针尺寸 0-8
minhandcolor	:分针颜色；传递颜色的10进制
sechandsize		:秒针尺寸 0-8
sechandcolor	:秒针颜色；传递颜色的10进制
nAutoset			:自适应位置设置，0为不1为是 如果为1，那txtleft/txttop/ weekleft/weektop/timeleft/timetop需要自己设坐标值
btxtcontent		:固定文字信息
btxtfontname	:固定文字字体
btimefontname	:时间文字字体
bweekfontname	:星期文字字体
bclockfontname:表盘文字字体
返回值            :详见返回状态代码定义。
-------------------------------------------------------------------------------* */
typedef int(__stdcall *pAddScreenProgramClockAreaFile)(int nScreenNo, int nProgramOrd, int nAreaOrd,
	int nusetxt, int nusetime, int nuseweek, int ntimeStyle, int nWeekStyle,
	int ntxtfontsize, int ntxtfontcolor, int ntxtbold, int ntxtitalic, int ntxtunderline, int txtleft, int txttop,
	int ntimefontsize, int ntimefontcolor, int ntimebold, int ntimeitalic, int ntimeunderline, int timeleft, int timetop,
	int nweekfontsize, int nweekfontcolor, int nweekbold, int nweekitalic, int nweekunderline, int weekleft, int weektop,
	int nclockfontsize, int nclockfontcolor, int nclockbold, int nclockitalic, int nclockunderline,
	int clockcentersize, int clockcentercolor, int mhrdotstyle, int mhrdotsize, int mhrdotcolor,
	int hrdotstyle, int hrdotsize, int hrdotcolor, int mindotstyle, int mindotsize, int mindotcolor,
	int hrhandsize, int hrhandcolor, int minhandsize, int minhandcolor, int sechandsize, int sechandcolor, int nAutoset,
	char* btxtcontent, char* btxtfontname, char* btimefontname, char* bweekfontname, char* bclockfontname);

typedef int(__stdcall *pAddScreenProgramChroArea)(int nScreenNo, int nProgramOrd, int nX, int nY, int nWidth, int nHeight);

/**---------------------------------------------------------------------------------------------
过程名:    AddScreenProgramChroAreaFile
向动态库中指定显示屏的指定节目的指定计时区域属性；该函数不与显示屏通讯，
只用于动态库中的指定显示屏指定节目中指定计时区域属性信息配置。
参数:
nScreenNo   :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
nProgramOrd :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
nAreaOrd    :区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
pInputtxt   :固定文字
pDaystr    :天单位
pHourstr   :小时单位
pMinstr    :分钟单位
pSecstr    :秒单位
pFontName   :文字的字体
nSingal     :单行多行，0为单行 1为多行，单行模式下nAlign不起作用
nAlign      :文字对齐模式，对多行有效，0为左1为中2为右
nFontSize   :文字的大小
nBold       :是否加粗，0为不1为是
nItalic     :是否斜体，0为不1为是
nUnderline  :是否下滑线，0为不1为是
nTxtcolor   :固定文字颜色，传递颜色的10进制 红255 绿65280 黄65535
nFontcolor  :计时显示颜色，传递颜色的10进制 红255 绿65280 黄65535
nShowstr     :是否显示单位，对应于所有的天，时，分，秒单位
nShowAdd     :是否计时累加显示 默认是累加的
nUsetxt     :是否使用固定文字，0为不1为是
nUseDay     :是否使用天，0为不1为是
nUseHour    :是否使用小时，0为不1为是
nUseMin     :是否使用分钟，0为不1为是
nUseSec     :是否使用秒，0为不1为是
nDayLength     :天显示位数    默认为0 自动
nHourLength    :小时显示位数  默认为0 自动
nMinLength     :分显示位数    默认为0 自动
nSecLength     :秒显示位数    默认为0 自动

EndYear     :目标年值
EndMonth   :目标月值
EndDay     :目标日值
EndHour    :目标时值
EndMin     :目标分值
EndSec     :目标秒值


nAutoset    :是否自动设置大小对应宽度，0为不1为是（默认不使用）
返回值            :详见返回状态代码定义。
----------------------------------------------------------------------* */
typedef int(__stdcall *pAddScreenProgramChroAreaFile)(int nScreenNo, int nProgramOrd, int nAreaOrd,
	char* pInputtxt, char* pDaystr, char* pHourstr, char* pMinstr, char* pSecstr, char* pFontName,
	int nSingal, int nAlign, int nFontSize, int nBold, int nItalic, int nUnderline,
	int nTxtcolor, int nFontcolor,
	int nShowstr, int nShowAdd, int nUseTxt, int nUseDay, int nUseHour, int nUseMin, int nUseSec,
	int nDayLength, int nHourLength, int nMinLength, int nSecLength,
	int EndYear, int EndMonth, int EndDay, int EndHour, int EndMin, int EndSec,
	int nAutoset);








#endif