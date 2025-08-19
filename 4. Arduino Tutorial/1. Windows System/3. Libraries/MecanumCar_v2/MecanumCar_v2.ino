/*
   麦克纳姆轮pico小车驱动库文件
   使用IO口模拟IIC通讯
   2022/7/4  dengfei
*/
#define SDA   20
#define SCL   21

/*******超声波传感器接口*****/
#define EchoPin  4  //ECHO to GPIO4
#define TrigPin  3  //TRIG to GPIO3

/*******各电机速度定义*****/
uint8_t speed_Upper_L = 80;
uint8_t speed_Lower_L = 80;
uint8_t speed_Upper_R = 80;
uint8_t speed_Lower_R = 80;
String speed_str;

void setup() {
  //Serial1.setTX(0); //蓝牙串口默认设置为UART0,TX为GPIO0
  //Serial1.setRX(1); //蓝牙串口默认设置为UART0,RX为GPIO1
  Serial1.begin(9600);  //设置蓝牙串波特率为9600

  mecanumCarInit();

  pinMode(EchoPin, INPUT);    //ECHO引脚设置为输入模式
  pinMode(TrigPin, OUTPUT);   //TRIG引脚设置为输出模式

}

void loop() {
  /*float distance_M = get_distance();
    Serial.println(distance_M, 2);
    delay(200);*/
  if (Serial1.available())//如果接收缓冲区非空
  {
    char ble_val = Serial1.read();//读取蓝牙数据
    Serial.println(ble_val);//串口打印读取到的数据
    switch (ble_val)
    {
      /*********************小车行驶************************/
      case 's': Stop();       break;  //停止
      case 'a': Advance();    break;  //前进
      case 'c': Back();       break;  //后退
      case 'b': Turn_Left();  break;  //左转
      case 'd': Turn_Right(); break;  //右转
      case 'k': L_Move();     break;  //左移
      case 'h': R_Move();     break;  //右移
      case 'l': LU_Move();    break;  //左上移
      case 'j': LD_Move();    break;  //左下移
      case 'g': RU_Move();    break;  //右上移
      case 'i': RD_Move();    break;  //右下移
      case 'e': drift_left(); break;  //漂移
      case 'f': drift_right(); break; //漂移
      /*********************小车灯光*************************/
      case 't': right_led(1);  left_led(1); break;  //开七彩灯
      case 'u': right_led(0);  left_led(0); break;  //关七彩灯
      /*********************小车调速*************************/
      case 'v':   /*读左前方电机M2的速度*/
        Serial1.readStringUntil('#');  //第一次接收到的速度值为空，先空读
        speed_str = Serial1.readStringUntil('#');  //第二次接收到速度数据，保存
        speed_Upper_L = String(speed_str).toInt();      //速度值为字符串格式，需要转换为整型
        speed_Upper_L = map(speed_Upper_L, 0, 100, 0, 255);  //从0~100映射到0~255
        //Serial.println(speed_Upper_L);  //串口调试
        break;
      case 'w':   /*读左后方电机M3的速度*/
        Serial1.readStringUntil('#');
        speed_str = Serial1.readStringUntil('#');
        speed_Lower_L = String(speed_str).toInt();
        speed_Lower_L = map(speed_Lower_L, 0, 100, 0, 255);
        //Serial.println(speed_Lower_L);
        break;
      case 'x':   /*读右前方电机M1的速度*/
        Serial1.readStringUntil('#');
        speed_str = Serial1.readStringUntil('#');
        speed_Upper_R = String(speed_str).toInt();
        speed_Upper_R = map(speed_Upper_R, 0, 100, 0, 255);
        //Serial.println(speed_Upper_R);
        break;
      case 'y':   /*读右后方电机M4的速度*/
        Serial1.readStringUntil('#');
        speed_str = Serial1.readStringUntil('#');
        speed_Lower_R = String(speed_str).toInt();
        speed_Lower_R = map(speed_Lower_R, 0, 100, 0, 255);
        //Serial.println(speed_Lower_R);
        break;

      default: break;
    }
  }
}








/*********************超声波测距*******************************/
float get_distance(void) {    //超声波测距
  float dis;
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH); //给TRIG至少10us的高电平以触发
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  dis = pulseIn(EchoPin, HIGH) / 58.2; //计算出距离
  delay(50);
  return dis;
}



void mecanumCarInit()
{
  delay(1000);
  pinMode(SDA, OUTPUT); //SDA总线为输出模式
  pinMode(SCL, OUTPUT); //SCL总线为输出模式
  right_led(0);
  left_led(0);
  Stop();
}


void Stop() {
  Motor_Upper_L(0, 0);
  Motor_Lower_L(0, 0);
  Motor_Upper_R(0, 0);
  Motor_Lower_R(0, 0);
}


void Advance()
{
  Motor_Upper_L(1, speed_Upper_L);
  Motor_Lower_L(1, speed_Lower_L);
  Motor_Upper_R(1, speed_Upper_R);
  Motor_Lower_R(1, speed_Lower_R);
}


void Back()
{
  Motor_Upper_L(0, speed_Upper_L);
  Motor_Lower_L(0, speed_Lower_L);
  Motor_Upper_R(0, speed_Upper_R);
  Motor_Lower_R(0, speed_Lower_R);
}


void Turn_Left()
{
  Motor_Upper_L(0, speed_Upper_L);
  Motor_Lower_L(0, speed_Lower_L);
  Motor_Upper_R(1, speed_Upper_R);
  Motor_Lower_R(1, speed_Lower_R);
}


void Turn_Right()
{
  Motor_Upper_L(1, speed_Upper_L);
  Motor_Lower_L(1, speed_Lower_L);
  Motor_Upper_R(0, speed_Upper_R);
  Motor_Lower_R(0, speed_Lower_R);
}



void L_Move()
{
  Motor_Upper_L(0, speed_Upper_L);
  Motor_Lower_L(1, speed_Lower_L);
  Motor_Upper_R(1, speed_Upper_R);
  Motor_Lower_R(0, speed_Lower_R);
}


void R_Move()
{
  Motor_Upper_L(1, speed_Upper_L);
  Motor_Lower_L(0, speed_Lower_L);
  Motor_Upper_R(0, speed_Upper_R);
  Motor_Lower_R(1, speed_Lower_R);
}


void LU_Move()
{
  Motor_Upper_L(0, 0);
  Motor_Lower_L(1, speed_Lower_L);
  Motor_Upper_R(1, speed_Upper_R);
  Motor_Lower_R(0, 0);
}


void LD_Move()
{
  Motor_Upper_L(0, speed_Upper_L);
  Motor_Lower_L(0, 0);
  Motor_Upper_R(0, 0);
  Motor_Lower_R(0, speed_Lower_R);
}



void RU_Move()
{
  Motor_Upper_L(1, speed_Upper_L);
  Motor_Lower_L(0, 0);
  Motor_Upper_R(0, 0);
  Motor_Lower_R(1, speed_Lower_R);
}


void RD_Move()
{
  Motor_Upper_L(0, 0);
  Motor_Lower_L(0, speed_Lower_L);
  Motor_Upper_R(0, speed_Upper_R);
  Motor_Lower_R(0, 0);
}


void drift_left()
{
  Motor_Upper_L(0, 0);
  Motor_Lower_L(0, speed_Lower_L);
  Motor_Upper_R(0, 0);
  Motor_Lower_R(1, speed_Lower_R);
}


void drift_right()
{
  Motor_Upper_L(0, 0);
  Motor_Lower_L(1, speed_Lower_L);
  Motor_Upper_R(0, 0);
  Motor_Lower_R(0, speed_Lower_R);
}



void Motor_Upper_L(bool stateL, int left1)
{
  if (stateL) {
    PWM_OUT(3, 0);
    PWM_OUT(4, left1);
  } else {
    PWM_OUT(3, left1);
    PWM_OUT(4, 0);
  }
}



void Motor_Lower_L(bool stateL, int left1)
{
  if (stateL) {
    PWM_OUT(7, 0);
    PWM_OUT(8, left1);
  } else {
    PWM_OUT(7, left1);
    PWM_OUT(8, 0);
  }
}




void Motor_Upper_R(bool stateR, int right1)
{
  if (stateR) {
    PWM_OUT(1, 0);
    PWM_OUT(2, right1);
  } else {
    PWM_OUT(1, right1);
    PWM_OUT(2, 0);
  }
}


void Motor_Lower_R(bool stateR, int right1)
{
  if (stateR) {
    PWM_OUT(5, 0);
    PWM_OUT(6, right1);
  } else {
    PWM_OUT(5, right1);
    PWM_OUT(6, 0);
  }
}


void right_led(bool onoff)
{
  digitalWrite_P55(onoff);
}


void left_led(bool onoff)
{
  digitalWrite_P54(onoff);
}



/**
  设置P55的数字信号输出
  val为写入的数字信号，1则输出高，0则输出低
**/
void digitalWrite_P55(bool val)
{
  Writebyte(0x0A, val);
}

/**
  设置P54的数字信号输出
  val为写入的数字信号，1则输出高，0则输出低
**/
void digitalWrite_P54(bool val)
{
  Writebyte(0x09, val);
}


/**
  PWM输出函数
  ch为PWM输出通道 1~8，val为写入的pwm值0~255
**/
void PWM_OUT(uint8_t ch, uint8_t pwm)
{
  Writebyte(ch, pwm);
}


/****指定地址写入1个字节数据  dat数据 addr寄存器地址*****/
void Writebyte(uint8_t addr, uint8_t dat)
{
  IIC_Start();
  IIC_SendByte(0x30<<1);
  IIC_RecvACK();
  IIC_SendByte(addr);
  IIC_RecvACK();
  IIC_SendByte(dat);
  IIC_RecvACK();
  IIC_Stop();
}


/***I2C起始信号***/
void IIC_Start() {
  digitalWrite(SDA, HIGH);
  delayMicroseconds(1);
  digitalWrite(SCL, HIGH); //拉高时钟线
  delayMicroseconds(1);  //延时2us
  digitalWrite(SDA, LOW);
  delayMicroseconds(1);
  digitalWrite(SCL, LOW);
  delayMicroseconds(1);
}

/*****I2C停止信号******/
void IIC_Stop() {
  digitalWrite(SCL, LOW);  //拉低数据线
  delayMicroseconds(1);
  digitalWrite(SDA, LOW);  //拉低时钟线
  delayMicroseconds(1);    //延时us
  digitalWrite(SCL, HIGH);
  delayMicroseconds(1);
  digitalWrite(SDA, HIGH);
  delayMicroseconds(1);
}

/**************************************
  发送应答信号
  入口参数:ack (0:ACK 1:NAK)
**************************************/
void IIC_SendACK(bool ack) {
  digitalWrite(SDA, ack);   //写应答信号
  delayMicroseconds(1);
  digitalWrite(SCL, HIGH);  //拉高时钟线，等待读取应答信号
  delayMicroseconds(1);  //延时
  digitalWrite(SCL, LOW);   //拉低时钟线
  delayMicroseconds(1);   //延时
}

/**************************************
  接收应答信号
**************************************/
bool IIC_RecvACK() {
  bool CY;
  digitalWrite(SCL, LOW);
  //digitalWrite(SDA, HIGH); //释放总线，<这里不拉高波形更好。。。>
  pinMode(SDA, INPUT);  //这里要读取信号，所以数据线设置为INPUT
  digitalWrite(SCL, HIGH);
  delayMicroseconds(1);
  CY = digitalRead(SDA);
  digitalWrite(SCL, LOW);
  pinMode(SDA, OUTPUT);//必须要重新设置输出模式
  return CY;
}

/**************************************
  向IIC总线发送一个字节数据
**************************************/
void IIC_SendByte(uint8_t dat) { //dat是要发送的一个字节的数据
  uint8_t i;
  for (i = 0; i < 8; i++) {  //高位开始传输
    digitalWrite(SCL, LOW);
    delayMicroseconds(1);
    if (0x80 & dat) digitalWrite(SDA, HIGH);  //置1
    else digitalWrite(SDA, LOW);  //置0
    dat <<= 1;
    delayMicroseconds(1);  //延时
    digitalWrite(SCL, HIGH);  //拉高时钟线 读取数据
    delayMicroseconds(1);
  }
}

/**************************************
  在IIC总线接收一个字节数据
**************************************/
uint8_t IIC_RecvByte() {
  digitalWrite(SDA, HIGH); //释放总线
  uint8_t i;
  uint8_t dat = 0;    //dat是存放接收到的一个字节的数据
  pinMode(SDA, INPUT);  //这里要读取信号，所以数据线设置为INPUT
  for (i = 0; i < 8; i++) {
    digitalWrite(SCL, HIGH);
    delayMicroseconds(1);
    dat <<= 1;
    if (digitalRead(SDA)) dat++;
    delayMicroseconds(1);
    digitalWrite(SCL, LOW);
    delayMicroseconds(1);
  }
  pinMode(SDA, OUTPUT);
  return dat;
}
