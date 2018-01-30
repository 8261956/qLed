#ifndef LEDDLL_H
#define LEDDLL_H





/*--------------------------���ļ�����------------------------------*/
typedef unsigned char byte;

typedef void(__stdcall *pCallBack)(char* szMessagge, int nProgress);//�ص�����ָ��

/*-------------------------------------------------------------------------------
������:    Initialize
��ʼ����̬�⣻�ú���������ʾ��ͨѶ��
DLLApp    :��������
pCallBack :���ط��͵���Ϣ�ͽ���
����Ϊ TCallBackFunc = procedure(szMessagge:string;nProgress:integer); stdcall;
����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pInitialize)(void* DllApp, pCallBack callBack);	//��ʼ����̬��


/*-------------------------------------------------------------------------------
������:    Uninitialize
��ʼ����̬�⣻�ú���������ʾ��ͨѶ��
����:
����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pUninitialize)();	//�ͷŶ�̬��


/*-------------------------------------------------------------------------------
������:    AddScreen
��̬���������ʾ����Ϣ���ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��������Ϣ���á�
����:
nControlType    :��ʾ���Ŀ������ͺţ�����궨�塰�������ͺŶ��塱
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
nScreenNo       :��ʾ�����ţ��ò�����LedshowTW 2013�����"��������"ģ���"����"����һ�¡�
nSendMode       :����ʾ����ͨѶģʽ��
0:����ģʽ��BX-5A2&RF��BX-5A4&RF�ȿ�����ΪRF��������ģʽ;
1:GPRSģʽ
2:����ģʽ
4:WiFiģʽ
5:ONBON������-GPRS
6:ONBON������-3G
nWidth          :��ʾ����� 16������������С64��BX-5Eϵ����СΪ80
nHeight         :��ʾ���߶� 16������������С16��
nScreenType     :��ʾ�����ͣ�1������ɫ��2��˫��ɫ��
3��˫��ɫ��ע�⣺����ʾ������ֻ��BX-4MC֧�֣�ͬʱ���ͺſ�������֧��������ʾ�����͡�
4��ȫ��ɫ��ע�⣺����ʾ������ֻ��BX-5Qϵ��֧�֣�ͬʱ���ͺſ�������֧��������ʾ�����͡�
5��˫��ɫ�Ҷȣ�ע�⣺����ʾ������ֻ��BX-5QS֧�֣�ͬʱ���ͺſ�������֧��������ʾ�����͡�
nPixelMode      :�������ͣ�1��R+G��2��G+R���ò���ֻ��˫��ɫ����Ч ��Ĭ��Ϊ2��
nDataDA         :���ݼ��ԣ���0x00�����ݵ���Ч��0x01�����ݸ���Ч��Ĭ��Ϊ0��
nDataOE         :OE���ԣ�  0x00��OE ����Ч��0x01��OE ����Ч��Ĭ��Ϊ0��
nRowOrder       :����ģʽ��0��������1����1�У�2����1�У�Ĭ��Ϊ0��
nFreqPar        :ɨ���Ƶ��0~6��Ĭ��Ϊ0��
pCom            :�������ƣ�����ͨѶģʽʱ��Ч����:COM1
nBaud           :���ڲ����ʣ�Ŀǰ֧��9600��57600��Ĭ��Ϊ57600��
pSocketIP       :���ƿ�IP��ַ������ͨѶģʽʱ��Ч����:192.168.0.199��
����̬������ͨѶģʽʱֻ֧�̶ֹ�IPģʽ������ֱ�������������ģʽ��֧�֡�
nSocketPort     :���ƿ�����˿ڣ�����ͨѶģʽʱ��Ч������5005
nStaticIPMode	�̶�IPͨѶģʽ  0��TCPģʽ  ��1��UDPģʽ
nServerMode     :0:������ģʽδ������1��������ģʽ������
pBarcode        :�豸������
pNetworkID      :������ģʽʱ������ID���
pServerIP       :��ת������IP��ַ
nServerPort     :��ת����������˿�
pServerAccessUser:��ת�����������û���
pServerAccessPassword:��ת��������������
pWiFiIP         :������WiFiģʽ��IP��ַ��Ϣ��WiFiͨѶģʽʱ��Ч����:192.168.100.1
nWiFiPort       :���ƿ�WiFi�˿ڣ�WiFiͨѶģʽʱ��Ч������5005
pGprsIP         :GPRS������IP��ַ
nGprsPort       :GPRS�������˿�
pGprsID         :GPRS���
pScreenStatusFile:���ڱ����ѯ������ʾ��״̬���������INI�ļ�����
ֻ��ִ�в�ѯ��ʾ��״̬GetScreenStatusʱ���ò�������Ч
����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pAddScreen)(int nControlType, int nScreenNo, int nSendMode,
	int nWidth, int nHeight, int nScreenType, int nPixelMode, int nDataDA,
	int nDataOE, int nRowOrder, int nDataFlow, int nFreqPar, char* pCom, int nBaud,
	char* pSocketIP, int nSocketPort, int nStaticIPMode, int nServerMode, char* pBarcode, char* pNetworkID,
	char* pServerIP, int nServerPort, char* pServerAccessUser, char* pServerAccessPassword,
	char* pWiFiIP, int nWiFiPort, char* pGprsIP, int nGprsPort, char* pGprsID, char* pScreenStatusFile); //�������

/*-------------------------------------------------------------------------------
������:    DeleteScreen
ɾ��ָ����ʾ����Ϣ��ɾ����ʾ���ɹ���Ὣ����ʾ�������н�Ŀ��Ϣ�Ӷ�̬����ɾ����
�ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��������Ϣ���á�
����:
nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}*/
typedef int(__stdcall *pDeleteScreen)(int nScreenNo);//ɾ������


/*-------------------------------------------------------------------------------
������:    DeleteScreen
ɾ��ָ����ʾ����Ϣ��ɾ����ʾ���ɹ���Ὣ����ʾ�������н�Ŀ��Ϣ�Ӷ�̬����ɾ����
�ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��������Ϣ���á�
����:
nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}*/
typedef int(__stdcall *pDeleteScreen)(int nScreenNo);//ɾ������
/*-------------------------------------------------------------------------------
������:    SendScreenInfo
ͨ��ָ����ͨѶģʽ��������Ӧ��Ϣ�������ʾ�����ú�������ʾ������ͨѶ
����:
nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nSendCmd        :ͨѶ����ֵ
SEND_CMD_PARAMETER =41471;  ������������
SEND_CMD_SENDALLPROGRAM = 41456;  �������н�Ŀ��Ϣ��
SEND_CMD_POWERON =41727; ǿ�ƿ���
SEND_CMD_POWEROFF = 41726; ǿ�ƹػ�
SEND_CMD_TIMERPOWERONOFF = 41725; ��ʱ���ػ�
SEND_CMD_CANCEL_TIMERPOWERONOFF = 41724; ȡ����ʱ���ػ�
SEND_CMD_RESIVETIME = 41723; У��ʱ�䡣
SEND_CMD_ADJUSTLIGHT = 41722; ���ȵ�����
nOtherParam1    :����������0
����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pSendScreenInfo)(int nScreenNo, int nSendCmd, int nOtherParam1);//������Ӧ�����ʾ����

/*-------------------------------------------------------------------------------
������:    AddScreenProgram
��̬����ָ����ʾ����ӽ�Ŀ���ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ����Ŀ��Ϣ���á�
����:
nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nProgramType    :��Ŀ���ͣ�0������Ŀ��
nPlayLength     :0:��ʾ�Զ�˳�򲥷ţ������ʾ��Ŀ���ŵĳ��ȣ���Χ1~65535����λ��
nStartYear      :��Ŀ���������ڣ���ʼ����ʱ����ݡ����Ϊ�����Ʋ��ŵĻ��ò���ֵΪ65535����2010
nStartMonth     :��Ŀ���������ڣ���ʼ����ʱ���·ݡ���11
nStartDay       :��Ŀ���������ڣ���ʼ����ʱ�����ڡ���26
nEndYear        :��Ŀ���������ڣ���������ʱ����ݡ���2011
nEndMonth       :��Ŀ���������ڣ���������ʱ���·ݡ���11
nEndDay         :��Ŀ���������ڣ���������ʱ�����ڡ���26
nMonPlay        :��Ŀ����������������һ�Ƿ񲥷�;0��������;1������.
nTuesPlay       :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
nWedPlay        :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
nThursPlay      :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
bFriPlay        :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
nSatPlay        :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
nSunPlay        :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
nStartHour      :��Ŀ�ڵ��쿪ʼ����ʱ��Сʱ����8
nStartMinute    :��Ŀ�ڵ��쿪ʼ����ʱ����ӡ���0
nEndHour        :��Ŀ�ڵ����������ʱ��Сʱ����18
nEndMinute      :��Ŀ�ڵ����������ʱ����ӡ���0
����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pAddScreenProgram)(int nScreenNo, int nProgramType, int nPlayLength,
	int nStartYear, int nStartMonth, int nStartDay, int nEndYear, int nEndMonth, int nEndDay,
	int nMonPlay, int nTuesPlay, int nWedPlay, int nThursPlay, int bFriPlay, int nSatPlay, int nSunPlay,
	int nStartHour, int nStartMinute, int nEndHour, int nEndMinute); //��ָ����ʾ����ӽ�Ŀ��

/*-------------------------------------------------------------------------------
������:    DeleteScreenProgram
ɾ��ָ����ʾ��ָ����Ŀ��ɾ����Ŀ�ɹ���Ὣ�ý�Ŀ������������Ϣɾ����
�ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��Ϣ���á�
����:
nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pDeleteScreenProgram)(int nScreenNo, int nProgramOrd); //ɾ����Ŀ

/*-------------------------------------------------------------------------------
������:    DeleteScreenProgramArea
ɾ��ָ����ʾ��ָ����Ŀ��ָ������ɾ������ɹ���Ὣ��������������Ϣɾ����
�ú���������ʾ��ͨѶ��ֻ���ڶ�̬����ָ����ʾ��ָ����Ŀ��ָ����������Ϣ���á�
����:
nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
nAreaOrd        :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pDeleteScreenProgramArea)(int nScreenNo, int nProgramOrd, int nAreaOrd);//ɾ������



/*-------------------------------------------------------------------------------
������:    QuerryServerDeviceList
��ѯ��ת�������豸���б���Ϣ��
�ú�������ʾ������ͨѶ
����:      nScreenNo, nSendMode: Integer
nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nSendMode       :����ʾ����ͨѶģʽ��
0:����ģʽ��BX-5A2&RF��BX-5A4&RF�ȿ�����ΪRF��������ģʽ;
2:����ģʽ;
4:WiFiģʽ
5:ONBON������-GPRS
6:ONBON������-3G
pDeviceList       : �����ѯ���豸�б���Ϣ
���豸����Ϣ������ַ���, ���磺
�豸1������ ������ ״̬ ���� ����ID
�豸2������ ������ ״̬ ���� ����ID
����ַ���Ϊ��'�豸1����,�豸1������,�豸1״̬,�豸1����,�豸1����ID;�豸2����,�豸2������,�豸2״̬,�豸2����,�豸2����ID'
�豸״̬(Byte):  $10:�豸δ֪
$11:�豸����
$12:�豸������

�豸����(Byte): $16:�豸Ϊ2G
$17:�豸Ϊ3G
pDeviceCount      : ��ѯ���豸����

����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pQuerryServerDeviceList)(int nScreenNo, int nSendMode, byte pDeviceList[], int &nDeviceCount);

/*-------------------------------------------------------------------------------
������:    BindServerDevice
����ת�������豸��
�ú���������ʾ������ͨѶ
����:      nScreenNo, nSendMode: Integer
nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
pBarcode       :���豸�������룻
pNetworkId     :���豸������ID��

����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pBindServerDevice)(int nScreenNo, char* pBarcode, char* pNetworkId);

/*-------------------------------------------------------------------------------
������:    SetScreenAdjustLight
�趨��ʾ�������ȵ����������ú����������ֹ������Ͷ�ʱ��������ģʽ���ú���������ʾ��ͨѶ��
ֻ���ڶ�̬���ж�ָ����ʾ�������ȵ�����Ϣ���á����轫�趨�����ȵ���ֵ���͵���ʾ���ϣ�
ֻ��ʹ��SendScreenInfo�����������ȵ�������ɡ�
����:
nScreenNo		:��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nAdjustType	:���ȵ������ͣ�0���ֹ�������1����ʱ����
nHandleLight:�ֹ�����������ֵ��ֻ��nAdjustType=0ʱ�ò�����Ч��
nHour1			:��һ�鶨ʱ����ʱ���Сʱ
nMinute1		:��һ�鶨ʱ����ʱ��ķ���
nLight1			:��һ�鶨ʱ����������ֵ
nHour2			:�ڶ��鶨ʱ����ʱ���Сʱ
nMinute2		:�ڶ��鶨ʱ����ʱ��ķ���
nLight2			:�ڶ��鶨ʱ����������ֵ
nHour3			:�����鶨ʱ����ʱ���Сʱ
nMinute3		:�����鶨ʱ����ʱ��ķ���
nLight3			:�����鶨ʱ����������ֵ
nHour4			:�����鶨ʱ����ʱ���Сʱ
nMinute4		:�����鶨ʱ����ʱ��ķ���
nLight4			:�����鶨ʱ����������ֵ
����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pSetScreenAdjustLight)(int nScreenNo, int nAdjustType, int nHandleLight,
	int nHour1, int nMinute1, int nLight1,
	int nHour2, int nMinute2, int nLight2,
	int nHour3, int nMinute3, int nLight3,
	int nHour4, int nMinute4, int nLight4);

/*-------------------------------------------------------------------------------
������:    SetScreenTimerPowerONOFF
�趨��ʾ���Ķ�ʱ���ػ���������������3�鿪�ػ�ʱ�䡣�ú���������ʾ��ͨѶ��
ֻ���ڶ�̬���ж�ָ����ʾ���Ķ�ʱ���ػ���Ϣ���á����轫�趨�Ķ�ʱ����ֵ���͵���ʾ���ϣ�
ֻ��ʹ��SendScreenInfo�������Ͷ�ʱ��������ɡ�
����:
nScreenNo		:��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nOnHour1		:��һ�鶨ʱ���صĿ���ʱ���Сʱ
nOnMinute1	:��һ�鶨ʱ���صĿ���ʱ��ķ���
nOffHour1		:��һ�鶨ʱ���صĹػ�ʱ���Сʱ
nOffMinute1	:��һ�鶨ʱ���صĹػ�ʱ��ķ���
nOnHour2		:�ڶ��鶨ʱ���صĿ���ʱ���Сʱ
nOnMinute2	:�ڶ��鶨ʱ���صĿ���ʱ��ķ���
nOffHour2		:�ڶ��鶨ʱ���صĹػ�ʱ���Сʱ
nOffMinute2	:�ڶ��鶨ʱ���صĹػ�ʱ��ķ���
nOnHour3		:�����鶨ʱ���صĿ���ʱ���Сʱ
nOnMinute3	:�����鶨ʱ���صĿ���ʱ��ķ���
nOffHour3		:�����鶨ʱ���صĹػ�ʱ���Сʱ
nOffMinute3	:�����鶨ʱ���صĹػ�ʱ��ķ���
����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pSetScreenTimerPowerONOFF)(int nScreenNo,
	int nOnHour1, int nOnMinute1, int nOffHour1, int nOffMinute1,
	int nOnHour2, int nOnMinute2, int nOffHour2, int nOffMinute2,
	int nOnHour3, int nOnMinute3, int nOffHour3, int nOffMinute3);

/*-------------------------------------------------------------------------------
������:    GetScreenStatus
��ѯ��ǰ��ʾ��״̬������ѯ״̬�������浽AddScreen�����е�pScreenStatusFile��INI�����ļ��С�
�ú�������ʾ������ͨѶ
����:      nScreenNo, nSendMode: Integer
nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nSendMode       :����ʾ����ͨѶģʽ��
0:����ģʽ��BX-5A2&RF��BX-5A4&RF�ȿ�����ΪRF��������ģʽ;
2:����ģʽ;
4:WiFiģʽ
����ֵ            :�������״̬���붨�塣
------------------------------------------------------------------------------ * */
typedef int(__stdcall *pGetScreenStatus)(int nScreenNo, int nSendMode);

/*-------------------------------------------------------------------------------
������:    SaveUSBScreenInfo
������ʾ��������Ϣ��USB�豸�������û���USB��ʽ������ʾ����Ϣ���ú�����LedshowTW������׵�USB���ع���һ�¡�
ʹ�øù���ʱ��ע�⵱ǰ�������Ƿ�֧��USB���ع��ܡ�
����:      nScreenNo, bCorrectTime: nAdvanceHour,nAdvanceMinute,pUSBDisk
nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
bCorrectTime       :�Ƿ�У��ʱ��
0����У��ʱ�䣻
1��У��ʱ�䡣
nAdvanceHour  :У��ʱ��ȵ�ǰ�����ʱ����ǰ��Сʱֵ����Χ0~23��ֻ�е�bCorrectTime=1ʱ��Ч��
nAdvanceMinute    :У��ʱ��ȵ�ǰ�����ʱ����ǰ�ķ���ֵ����Χ0~59��ֻ�е�bCorrectTime=1ʱ��Ч��
pUSBDisk  :USB�豸��·�����ƣ���ʽΪ"�̷�:\"�ĸ�ʽ��
����ֵ            :�������״̬���붨�塣
------------------------------------------------------------------------------ * */
typedef int(__stdcall *pSaveUSBScreenInfo)(int nScreenNo, int bCorrectTime, int nAdvanceHour, int nAdvanceMinute, char* pUSBDisk);


/*-------------------------------------------------------------------------------
������:    AddScreenProgramBmpTextArea:
��̬����ָ����ʾ����ָ����Ŀ���ͼ�����򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ�е�ͼ��������Ϣ���á�
����:
nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pAddScreenProgramBmpTextArea)(int nScreenNo, int nProgramOrd, int nX, int nY,
	int nWidth, int nHeight);//��ָ����ʾ��ָ����Ŀ���ͼ������


/*-------------------------------------------------------------------------------
������:    AddScreenProgramAreaBmpTextFile
��̬����ָ����ʾ����ָ����Ŀ��ָ��ͼ����������ļ���
�ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ��ͼ��������ļ���Ϣ���á�
����:
nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
nAreaOrd        :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
pFileName       :�ļ�����  ֧��.bmp,jpg,jpeg,rtf,txt���ļ����͡�
nShowSingle     :����������ʾ��1��������ʾ��0��������ʾ���ò���ֻ����pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
pFontName       :�������ƣ�֧�ֵ�ǰ����ϵͳ�Ѿ���װ��ʸ���ֿ⣻�ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
nFontSize       :�����ֺţ�֧�ֵ�ǰ����ϵͳ���ֺţ��ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
nBold           :������壻֧��1�����壻0���������ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
nFontColor      :������ɫ���ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
nStunt          :��ʾ�ؼ���
0x00:�����ʾ
0x01:��̬
0x02:���ٴ��
0x03:�����ƶ�
0x04:��������
0x05:�����ƶ�            3T���Ϳ��ƿ��޴��ؼ�
0x06:��������            3T���Ϳ��ƿ��޴��ؼ�
0x07:��˸                3T���Ϳ��ƿ��޴��ؼ�
0x08:Ʈѩ
0x09:ð��
0x0A:�м��Ƴ�
0x0B:��������
0x0C:���ҽ�������
0x0D:���½�������
0x0E:����պ�
0x0F:�����
0x10:��������
0x11:��������
0x12:��������
0x13:��������            3T���Ϳ��ƿ��޴��ؼ�
0x14:��������
0x15:��������
0x16:��������
0x17:��������
0x18:���ҽ�����Ļ
0x19:���½�����Ļ
0x1A:��ɢ����
0x1B:ˮƽ��ҳ            3T��3A��4A��3A1��3A2��4A1��4A2��4A3��4AQ���Ϳ��ƿ��޴��ؼ�
0x1C:��ֱ��ҳ            3T��3A��4A��3A1��3A2��4A1��4A2��4A3��4AQ��3M��4M��4M1��4MC���Ϳ��ƿ��޴��ؼ�
0x1D:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
0x1E:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
0x1F:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
0x20:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
0x21:���ұպ�            3T���Ϳ��ƿ��޴��ؼ�
0x22:���ҶԿ�            3T���Ϳ��ƿ��޴��ؼ�
0x23:���±պ�            3T���Ϳ��ƿ��޴��ؼ�
0x24:���¶Կ�            3T���Ϳ��ƿ��޴��ؼ�
0x25:��������
0x26:��������
0x27:�����ƶ�            3T���Ϳ��ƿ��޴��ؼ�
0x28:��������            3T���Ϳ��ƿ��޴��ؼ�
nRunSpeed       :�����ٶȣ�0~63��ֵԽ�������ٶ�Խ����
nShowTime       :ͣ��ʱ�䣻0~65525����λ0.5��

����ֵ:           :�������״̬���붨�塣
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pAddScreenProgramAreaBmpTextFile)(int nScreenNo, int nProgramOrd, int nAreaOrd,
	char* pFileName, int nShowSingle, int nHorAlign, int nVerAlign, char* pFontName, int nFontSize, int nBold, int nItalic, int nUnderline, int nFontColor,
	int nStunt, int nRunSpeed, int nShowTime, int nStretch, int nShift); //��ָ����ʾ��ָ����Ŀָ����������ļ�

/*-------------------------------------------------------------------------------
������:    AddScreenProgramAreaBmpTextText
��̬����ָ����ʾ����ָ����Ŀ��ָ��ͼ����������ı���
�ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ��ͼ��������ļ���Ϣ���á�
����:
nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
nAreaOrd        :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
pFileName       :�ı�
nShowSingle     :����������ʾ��1��������ʾ��0��������ʾ���ò���ֻ����pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
pFontName       :�������ƣ�֧�ֵ�ǰ����ϵͳ�Ѿ���װ��ʸ���ֿ⣻�ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
nFontSize       :�����ֺţ�֧�ֵ�ǰ����ϵͳ���ֺţ��ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
nBold           :������壻֧��1�����壻0���������ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
nFontColor      :������ɫ���ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
nStunt          :��ʾ�ؼ���
0x00:�����ʾ
0x01:��̬
0x02:���ٴ��
0x03:�����ƶ�
0x04:��������
0x05:�����ƶ�            3T���Ϳ��ƿ��޴��ؼ�
0x06:��������            3T���Ϳ��ƿ��޴��ؼ�
0x07:��˸                3T���Ϳ��ƿ��޴��ؼ�
0x08:Ʈѩ
0x09:ð��
0x0A:�м��Ƴ�
0x0B:��������
0x0C:���ҽ�������
0x0D:���½�������
0x0E:����պ�
0x0F:�����
0x10:��������
0x11:��������
0x12:��������
0x13:��������            3T���Ϳ��ƿ��޴��ؼ�
0x14:��������
0x15:��������
0x16:��������
0x17:��������
0x18:���ҽ�����Ļ
0x19:���½�����Ļ
0x1A:��ɢ����
0x1B:ˮƽ��ҳ            3T��3A��4A��3A1��3A2��4A1��4A2��4A3��4AQ���Ϳ��ƿ��޴��ؼ�
0x1C:��ֱ��ҳ            3T��3A��4A��3A1��3A2��4A1��4A2��4A3��4AQ��3M��4M��4M1��4MC���Ϳ��ƿ��޴��ؼ�
0x1D:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
0x1E:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
0x1F:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
0x20:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
0x21:���ұպ�            3T���Ϳ��ƿ��޴��ؼ�
0x22:���ҶԿ�            3T���Ϳ��ƿ��޴��ؼ�
0x23:���±պ�            3T���Ϳ��ƿ��޴��ؼ�
0x24:���¶Կ�            3T���Ϳ��ƿ��޴��ؼ�
0x25:��������
0x26:��������
0x27:�����ƶ�            3T���Ϳ��ƿ��޴��ؼ�
0x28:��������            3T���Ϳ��ƿ��޴��ؼ�
nRunSpeed       :�����ٶȣ�0~63��ֵԽ�������ٶ�Խ����
nShowTime       :ͣ��ʱ�䣻0~65525����λ0.5��

����ֵ:           :�������״̬���붨�塣
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pAddScreenProgramAreaBmpTextText)(int nScreenNo, int nProgramOrd, int nAreaOrd,
	char* pText, int nShowSingle, int nHorAlign, int  nVerAlign, char* pFontName, int nFontSize, int nBold, int nItalic, int nUnderline, int nFontColor,
	int nStunt, int nRunSpeed, int nShowTime, int nStretch, int nShift); //��ָ����ʾ��ָ����Ŀָ����������ļ�

/*-------------------------------------------------------------------------------
������:    DeleteScreenProgramAreaBmpTextFile
ɾ��ָ����ʾ��ָ����Ŀָ��ͼ�������ָ���ļ���ɾ���ļ��ɹ���Ὣ���ļ���Ϣɾ����
�ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀָ�������е�ָ���ļ���Ϣ���á�
����:
nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
nAreaOrd        :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
nFileOrd        :�ļ���ţ�����Ű����ļ����˳�򣬴�0˳���������ɾ���м���ļ���������ļ�����Զ���䡣
����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------*/
typedef int(__stdcall *pDeleteScreenProgramAreaBmpTextFile)(int nScreenNo, int nProgramOrd, int nAreaOrd, int nFileOrd); //ɾ��ָ����ʾ��ָ����Ŀָ��ͼ�������ָ���ļ���ɾ���ļ��ɹ���Ὣ���ļ���Ϣɾ��

/*-------------------------------------------------------------------------------
������:    AddScreenProgramTimeArea
��̬����ָ����ʾ����ָ����Ŀ���ʱ�����򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ�е�ʱ��������Ϣ���á�
����:
nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
����ֵ            :�������״̬���붨�塣
-----------------------------------------------------------------------------*/
typedef int(__stdcall *pAddScreenProgramTimeArea)(int nScreenNo,
	int nProgramOrd, int nX, int nY, int nWidth, int nHeight);

/*--------------------------------------------------------------------------
������:    AddScreenProgramTimeAreaFile
��̬����ָ����ʾ����ָ����Ŀ��ָ��ʱ���������ԣ��ú���������ʾ��ͨѶ��
ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ��ʱ������������Ϣ���á�
����:
nScreenNo   :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nProgramOrd :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
nAreaOrd    :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
pInputtxt   :�̶�����
pFontName   :���ֵ�����
nSingal     :���ж��У�0Ϊ���� 1Ϊ���У�����ģʽ��nAlign��������
nAlign      :���ֶ���ģʽ���Զ�����Ч��0Ϊ��1Ϊ��2Ϊ��
nFontSize   :���ֵĴ�С
nBold       :�Ƿ�Ӵ֣�0Ϊ��1Ϊ��
nItalic     :�Ƿ�б�壬0Ϊ��1Ϊ��
nUnderline  :�Ƿ��»��ߣ�0Ϊ��1Ϊ��
nUsetxt     :�Ƿ�ʹ�ù̶����֣�0Ϊ��1Ϊ��
nTxtcolor   :�̶�������ɫ��������ɫ��10���� ��255 ��65280 ��65535
nUseymd     :�Ƿ�ʹ�������գ�0Ϊ��1Ϊ��
nYmdstyle   :�����ո�ʽ�����ʹ��˵���ĵ��ĸ���1
nYmdcolor   :��������ɫ��������ɫ��10����
nUseweek    :�Ƿ�ʹ�����ڣ�0Ϊ��1Ϊ��
nWeekstyle  :���ڸ�ʽ�����ʹ��˵���ĵ��ĸ���1
nWeekcolor  :������ɫ��������ɫ��10����
nUsehns     :�Ƿ�ʹ��ʱ���룬0Ϊ��1��
nHnsstyle   :ʱ�����ʽ�����ʹ��˵���ĵ��ĸ���1
nHnscolor   :ʱ������ɫ��������ɫ��10����
nAutoset    :�Ƿ��Զ����ô�С��Ӧ��ȣ�0Ϊ��1Ϊ�ǣ�Ĭ�ϲ�ʹ�ã�
����ֵ            :�������״̬���붨�塣
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
������:    AddScreenProgramLunarArea
��̬����ָ����ʾ����ָ����Ŀ���ũ�����򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ�е�ũ��������Ϣ���á�
����:
nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
����ֵ            :�������״̬���붨�塣
---------------------------------------------------------------------------}
------------------------------------------------------------------------- * */
typedef int(__stdcall *pAddScreenProgramLunarArea)(int nScreenNo, int nProgramOrd,
	int nX, int nY, int nWidth, int nHeight);

/*-------------------------------------------------------------------------------
������:    AddScreenProgramLunarAreaFile
��̬����ָ����ʾ����ָ����Ŀ��ָ��ũ���������ԣ��ú���������ʾ��ͨѶ��
ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ��ũ������������Ϣ���á�
����:
nScreenNo		:��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nProgramOrd	:��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
nAreaOrd		:������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
pInputtxt		:�̶�����
pFontName		:���ֵ�����
nSingal			:���ж��У�0Ϊ���� 1Ϊ���У�����ģʽ��nAlign��������
nAlign			:���ֶ���ģʽ���Զ�����Ч��0Ϊ��1Ϊ��2Ϊ��
nFontSize		:���ֵĴ�С
nBold				:�Ƿ�Ӵ֣�0Ϊ��1Ϊ��
nItalic			:�Ƿ�б�壬0Ϊ��1Ϊ��
nUnderline	:�Ƿ��»��ߣ�0Ϊ��1Ϊ��
nUsetxt			:�Ƿ�ʹ�ù̶����֣�0Ϊ��1Ϊ��
nTxtcolor		:�̶�������ɫ��������ɫ��10����
nUseyear		:�Ƿ�ʹ����ɣ�0Ϊ��1Ϊ��  ����î���꣩
nYearcolor	:�����ɫ��������ɫ��10����
nUsemonth		:�Ƿ�ʹ��ũ����0Ϊ��1Ϊ��  ��������ʮ��
nMonthcolor	:ũ����ɫ��������ɫ��10����
nUsesolar		:�Ƿ�ʹ�ý�����0Ϊ��1��
nSolarcolor	:������ɫ��������ɫ��10����
nAutoset		:�Ƿ��Զ����ô�С��Ӧ��ȣ�0Ϊ��1Ϊ�ǣ�Ĭ�ϲ�ʹ�ã�
����ֵ            :�������״̬���붨�塣
-----------------------------------------------------------------------}
-----------------------------------------------------------------------* */
typedef int(__stdcall *pAddScreenProgramLunarAreaFile)(int nScreenNo, int nProgramOrd, int nAreaOrd,
	char* pInputtxt, char* pFontName,
	int nSingal, int nAlign, int nFontSize, int nBold, int nItalic, int nUnderline,
	int nUsetxt, int nTxtcolor, int nUseyear, int nYearcolor, int nUsemonth, int nMonthcolor,
	int nUsesolar, int nSolarcolor, int nAutoset);
/*----------------------------------------------------------------------------
������:    AddScreenProgramClockArea
��̬����ָ����ʾ����ָ����Ŀ��ӱ������򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ�еı���������Ϣ���á�
����:
nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
����ֵ            :�������״̬���붨�塣
-------------------------------------------------------------------------------}
-------------------------------------------------------------------------------* */
typedef int(__stdcall *pAddScreenProgramClockArea)(int nScreenNo, int nProgramOrd,
	int nX, int nY, int nWidth, int nHeight);

/*-------------------------------------------------------------------------
������:    AddScreenProgramClockAreaFile
��̬����ָ����ʾ����ָ����Ŀ��ָ�������������ԣ��ú���������ʾ��ͨѶ��
ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ����������������Ϣ���á�
����:
nScreenNo			:��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nProgramOrd 	:��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
nAreaOrd			:������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
nusetxt				:�Ƿ�ʹ�ù̶����� 0Ϊ��1Ϊ��
nusetime			:�Ƿ�ʹ��������ʱ�� 0Ϊ��1Ϊ��
nuseweek			:�Ƿ�ʹ������ 0Ϊ��1Ϊ��
ntimeStyle		:������ʱ���ʽ���ο�ʱ�����ı��˵��
nWeekStyle		:����ʱ���ʽ���ο�ʱ�����ı��˵��
ntxtfontsize	:�̶����ֵ��ִ�С
ntxtfontcolor	:�̶����ֵ���ɫ��������ɫ��10����;��255��65280��65535
ntxtbold			:�̶������Ƿ�Ӵ� 0Ϊ��1Ϊ��
ntxtitalic		:�̶������Ƿ�б�� 0Ϊ��1Ϊ��
ntxtunderline	:�̶������Ƿ��»��� 0Ϊ��1Ϊ��
txtleft				:�̶������ڱ��������е�X����
txttop				:�̶������ڱ��������е�Y����
ntimefontsize	:���������ֵ��ִ�С
ntimefontcolor:���������ֵ���ɫ�� ������ɫ��10����
ntimebold			:�����������Ƿ�Ӵ� 0Ϊ��1Ϊ��
ntimeitalic		:�����������Ƿ�б�� 0Ϊ��1Ϊ��
ntimeunderline:�����������Ƿ��»��� 0Ϊ��1Ϊ��
timeleft			:�����������ڱ��������е�X����
timetop				:�����������ڱ��������е�X����
nweekfontsize	:�������ֵ��ִ�С
nweekfontcolor:�������ֵ���ɫ��������ɫ��10����
nweekbold			:���������Ƿ�Ӵ� 0Ϊ��1Ϊ��
nweekitalic		:���������Ƿ�б�� 0Ϊ��1Ϊ��
nweekunderline:���������Ƿ��»��� 0Ϊ��1Ϊ��
weekleft			:���������ڱ��������е�X����
weektop				:���������ڱ��������е�X����
nclockfontsize:�������ֵ��ִ�С
nclockfontcolor:�������ֵ���ɫ��������ɫ��10����
nclockbold		:���������Ƿ�Ӵ� 0Ϊ��1Ϊ��
nclockitalic	:���������Ƿ�б�� 0Ϊ��1Ϊ��
nclockunderline:���������Ƿ��»��� 0Ϊ��1Ϊ��
clockcentercolor:����������ɫ��������ɫ��10����
mhrdotstyle		:3/6/9ʱ������ 0����1Բ��2����3����4����
mhrdotsize		:3/6/9ʱ��ߴ� 0-8
mhrdotcolor		:3/6/9ʱ����ɫ��������ɫ��10����
hrdotstyle		:3/6/9���ʱ������  0����1Բ��2����3����4����
hrdotsize			:3/6/9���ʱ��ߴ� 0-8
hrdotcolor		:3/6/9���ʱ����ɫ��������ɫ��10����
mindotstyle		:���ӵ�����  0����1Բ��2����
mindotsize		:���ӵ�ߴ� 0-1
mindotcolor		:���ӵ���ɫ��������ɫ��10����
hrhandsize		:ʱ��ߴ� 0-8
hrhandcolor		:ʱ����ɫ��������ɫ��10����
minhandsize		:����ߴ� 0-8
minhandcolor	:������ɫ��������ɫ��10����
sechandsize		:����ߴ� 0-8
sechandcolor	:������ɫ��������ɫ��10����
nAutoset			:����Ӧλ�����ã�0Ϊ��1Ϊ�� ���Ϊ1����txtleft/txttop/ weekleft/weektop/timeleft/timetop��Ҫ�Լ�������ֵ
btxtcontent		:�̶�������Ϣ
btxtfontname	:�̶���������
btimefontname	:ʱ����������
bweekfontname	:������������
bclockfontname:������������
����ֵ            :�������״̬���붨�塣
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
������:    AddScreenProgramChroAreaFile
��̬����ָ����ʾ����ָ����Ŀ��ָ����ʱ�������ԣ��ú���������ʾ��ͨѶ��
ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ����ʱ����������Ϣ���á�
����:
nScreenNo   :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
nProgramOrd :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
nAreaOrd    :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
pInputtxt   :�̶�����
pDaystr    :�쵥λ
pHourstr   :Сʱ��λ
pMinstr    :���ӵ�λ
pSecstr    :�뵥λ
pFontName   :���ֵ�����
nSingal     :���ж��У�0Ϊ���� 1Ϊ���У�����ģʽ��nAlign��������
nAlign      :���ֶ���ģʽ���Զ�����Ч��0Ϊ��1Ϊ��2Ϊ��
nFontSize   :���ֵĴ�С
nBold       :�Ƿ�Ӵ֣�0Ϊ��1Ϊ��
nItalic     :�Ƿ�б�壬0Ϊ��1Ϊ��
nUnderline  :�Ƿ��»��ߣ�0Ϊ��1Ϊ��
nTxtcolor   :�̶�������ɫ��������ɫ��10���� ��255 ��65280 ��65535
nFontcolor  :��ʱ��ʾ��ɫ��������ɫ��10���� ��255 ��65280 ��65535
nShowstr     :�Ƿ���ʾ��λ����Ӧ�����е��죬ʱ���֣��뵥λ
nShowAdd     :�Ƿ��ʱ�ۼ���ʾ Ĭ�����ۼӵ�
nUsetxt     :�Ƿ�ʹ�ù̶����֣�0Ϊ��1Ϊ��
nUseDay     :�Ƿ�ʹ���죬0Ϊ��1Ϊ��
nUseHour    :�Ƿ�ʹ��Сʱ��0Ϊ��1Ϊ��
nUseMin     :�Ƿ�ʹ�÷��ӣ�0Ϊ��1Ϊ��
nUseSec     :�Ƿ�ʹ���룬0Ϊ��1Ϊ��
nDayLength     :����ʾλ��    Ĭ��Ϊ0 �Զ�
nHourLength    :Сʱ��ʾλ��  Ĭ��Ϊ0 �Զ�
nMinLength     :����ʾλ��    Ĭ��Ϊ0 �Զ�
nSecLength     :����ʾλ��    Ĭ��Ϊ0 �Զ�

EndYear     :Ŀ����ֵ
EndMonth   :Ŀ����ֵ
EndDay     :Ŀ����ֵ
EndHour    :Ŀ��ʱֵ
EndMin     :Ŀ���ֵ
EndSec     :Ŀ����ֵ


nAutoset    :�Ƿ��Զ����ô�С��Ӧ��ȣ�0Ϊ��1Ϊ�ǣ�Ĭ�ϲ�ʹ�ã�
����ֵ            :�������״̬���붨�塣
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