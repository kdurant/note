# PyQt5程序基本结构

## 从QMainWindow继承
```python
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *

class window(QMainWindow):
    def __init__(self):
        super(window, self).__init__()
        self.initUI()

    def initUI(self):

        layout = QVBoxLayout()
        layout.addWidget(qmc)

        self.main_frame = QWidget(self)
        self.main_frame.setLayout(layout)
        self.setCentralWidget(self.main_frame)
        
if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)
    ui = window()
    ui.show()
    sys.exit(app.exec_())
```

# 利用QtDesigner设计UI界面 

## 函数实现
1. 使用QtDesigner设计好UI界面

2. 将xx.ui文件转换成python格式
`python3 -m PyQt5.uic.pyuic mainwindow.ui -o test_ui.py`
`pyuic5 mainwindow.ui -o test_ui.py`

3. 基本程序结构
```python
if __name__ == "__main__":
    app = QApplication(sys.argv)
    mainWindow = QMainWindow()
    ui = Ui_MainWindow()    # test_ui里的类名称
    ui.setupUi(mainWindow)
    mainWindow.show()
    sys.exit(app.exec_())
```

## 继承QMainWindow实现
```python
import sys
from PyQt5.QtWidgets import QApplication, QWidget, QMainWindow
from test_ui import *

class MyWindow(QMainWindow):
    def __init__(self):
        super(MyWindow, self).__init__()
        self.ui = Ui_Form()  # 工具生成的界面类
        self.ui.setupUi(self)

        self.ui.pushButton.clicked.connect(self.change_text)

        def change_text(self):
            self.ui.pushButton.setText('nihaobbbbb')
            QtWidgets.QMessageBox.information(self.ui.pushButton,"标题","这是第一个PyQt5 GUI程序")

if __name__ == "__main__":
    app = QApplication(sys.argv)
    myWindow = MyWindow()
    myWindow.show()
    sys.exit(app.exec_())
```
## 继承QMainWindow, Ui_Form实现

```python
import sys
from PyQt5.QtWidgets import QApplication, QWidget, QMainWindow
from test_ui import *

class MyWindow(QMainWindow, Ui_Form):
    def __init__(self):
        QMainWindow.__init__(self)
        Ui_Form.__init__(self)
    self.setupUi(self)

        self.pushButton.clicked.connect(self.change_text)
    def change_text(self):
        self.pushButton.setText('nihaobbbbb')
        QtWidgets.QMessageBox.information(self.pushButton,"标题","这是第一个PyQt5 GUI程序")

if __name__ == "__main__":
    app = QApplication(sys.argv)
    myWindow = MyWindow()
    myWindow.show()
    sys.exit(app.exec_())
```
## 总结
1. 界面文件里不包含信号和槽函数的实现，实现界面与逻辑代码的分离
2. 双继承时，可以直接调用UI文件里控件

# 标签 QLabel
```python
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
import sys

class window(QMainWindow):
    def __init__(self):
        super(window, self).__init__()
        self.initUI()

    def initUI(self):
        self.main_frame = QWidget(self)
        layout = QVBoxLayout()

        label = QLabel('wang')
        label.setFixedWidth(400)  # 设置label宽度
        label.setFixedHeight(40)  # 设置label高度
        label.setAlignment(Qt.AlignCenter)  # 设置label内容对齐方式
        label.setText(u"王")
        label.setFont(QFont("Roman times", 20, QFont.Bold)) # 设置字体
        label.setToolTip('hello world')     # 设置提示
        label.setPixmap(QPixmap('send.svg'))    # 设置图标内容为图片
        label.setPixmap(QPixmap('images/debug.svg').scaled(QSize(150, 150)))    # 缩放label里的图片

        print(label.text()) # 获得label内容

        # 设置字体颜色及背景色
        pe = QPalette()
        pe.setColor(QPalette.WindowText, Qt.red)
        label.setAutoFillBackground(True)
        pe.setColor(QPalette.Window,Qt.blue)
        #pe.setColor(QPalette.Background,Qt.blue)
        label.setPalette(pe)

        layout.addWidget(label)
        self.main_frame.setLayout(layout)
        self.setCentralWidget(self.main_frame)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    ui = window()
    ui.show()
    sys.exit(app.exec_())
```

# 按键 QPushButton
```python
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
import sys


class window(QMainWindow):
    def __init__(self):
        super(window, self).__init__()
        self.initUI()

    def initUI(self):
        self.main_frame = QWidget(self)
        layout = QVBoxLayout()

        closeButton = QPushButton(self)
        closeButton.setText("Close")            # 设置按钮文本
        closeButton.setIcon(QIcon("./images/play.png"))     # 设置按钮图标
        closeButton.setIconSize(QSize(48, 48))
        closeButton.setShortcut('Ctrl+D')   # 设置按钮快捷键
        closeButton.setToolTip("Close the widget")      # 设置提示

        closeButton.setFixedWidth(400)  # 设置控件宽度
        closeButton.setFixedHeight(40)  # 设置控件高度
        # 不能设置btn内容对齐方式
        closeButton.setFont(QFont("Roman times", 20, QFont.Bold)) # 设置字体
        closeButton.setEnabled(False)   # 按钮无效变灰

        closeButton.clicked.connect(self.close)

        layout.addWidget(closeButton)
        self.main_frame.setLayout(layout)
        self.setCentralWidget(self.main_frame)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    ui = window()
    ui.show()
    sys.exit(app.exec_())
```

# 行文本输入 QLineEdit
```python
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
import sys

class window(QMainWindow):
    def __init__(self):
        super(window, self).__init__()
        self.initUI()

    def initUI(self):
        self.main_frame = QWidget(self)
        layout = QVBoxLayout()

        #line = QLineEdit('123')     # 声明且设置默认显示内容
        line = QLineEdit()
        #line.setText('abc')         # 设置显示内容
        print(line.displayText())   # 获取lineedit里内容
        line.setMaxLength(100)       # 输入文本的长度限制, 默认值是32767
        line.setPlaceholderText("Normal");  # 设置占位符
        line.setReadOnly(False)      # 是否只读. True只读
        line.setDragEnabled(False)  # 是否允许拖拽内容. True允许

        # line.setEchoMode(QLineEdit.Normal)      # 默认模式，正常显示
        # line.setEchoMode(QLineEdit.NoEcho)      # 完全不显示输入，部分操作被禁止
        # line.setEchoMode(QLineEdit.Password)    # 密码模式,像输入密码那样,把输入内容变成一个个圆圈
        # line.setEchoMode(QLineEdit.PasswordEchoOnEdit)  # 输入时显示内容,失去焦点时内容变成圆圈

        layout.addWidget(line)
        self.main_frame.setLayout(layout)
        self.setCentralWidget(self.main_frame)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    ui = window()
    ui.show()
    sys.exit(app.exec_())
```

# 文件选择

```python
from PyQt5.QtWidgets import QFileDialog  

# btn信号连接自定义槽函数
self.open_file_btn.clicked.connect(self.open_file)  # 打开文件选择对话框

directory1 = QFileDialog.getExistingDirectory(self,  "选取文件夹",  os.getcwd())       #起始路径  
fileName1, filetype = QFileDialog.getOpenFileName(self,  
                            "选取文件",  
                            os.getcwd(),  
                            "All Files (*)")   #设置文件扩展名过滤,注意用双分号间隔  
```

# 定时器 QTimer
```python
from PyQt5.QtCore import QTimer
self.timer = QTimer()
self.timer.start(2000)

self.timer.timeout.connect(self.change_text)

self.timer.setInterval(1000)    # 重新设置定时器间隔
```

# QGroupBox
提供一个带有标题的框架
```python
def createFirstExclusiveGroup(self):
    # 1. 声明 groupbox
    groupBox = QGroupBox("Exclusive Radio Buttons")
    groupBox.setFlat(True)  # 设置为True时，只显示上方边界线

    # 2. 添加控件及其设置
    radio1 = QRadioButton("&Radio button 1")
    radio2 = QRadioButton("R&adio button 2")
    radio3 = QRadioButton("Ra&dio button 3")

    radio1.setChecked(True)

    # 3. 布局管理器里添加控件
    vbox = QVBoxLayout()
    vbox.addWidget(radio1)
    vbox.addWidget(radio2)
    vbox.addWidget(radio3)
    vbox.addStretch(1)

    # 使能布局管理器
    groupBox.setLayout(vbox)

    '''
    有return时，函数可以当作widget添加到布局管理器中
    grid.addWidget(self.createFirstExclusiveGroup(), 0, 0)
    '''
    return groupBox
```
layout也可以这样使用。
```python
    def createFileGroup(self):
        self.load_file_btn = QPushButton("打开文件")
        self.load_file_btn.setIcon(QIcon('./images/open.png'))

        self.land_rbtn = QRadioButton("&陆地雷达")
        self.land_rbtn.setCheckable(True)
        self.ocean_rbtn = QRadioButton("&海洋雷达")

        hlyt = QHBoxLayout()
        hlyt.addWidget(self.load_file_btn)
        hlyt.addWidget(self.land_rbtn)
        hlyt.addWidget(self.ocean_rbtn)
        return hlyt
        '''
        可以在其他地方调用
        left_vlyt.addLayout(self.createFileGroup())
        '''
```

# 消息框 QMessageBox
```python
QMessageBox.information(self, "警告", "请先加载文件")
QMessageBox.information(self, "标题", "对话框消息正文", QMessageBox.Yes | QMessageBox.No ,  QMessageBox.Yes )  
```

# QSplitter
QSplitter里无法添加Layout对象，只能添加Widget对象
```python
        # 1. 声明
        top_splitter = QSplitter(Qt.Horizontal)
        # 2. 讲布局好的Layout对象添加到QFrame里
        frame1 = QFrame()
        frame1.setLayout(left_vlyt)
        frame2 = QFrame()
        frame2.setLayout(right_vlyt)
        # 3. 添加QFrame，这样水平布置的两个布局就可以左右拉动大小了
        top_splitter.addWidget(frame1)
        top_splitter.addWidget(frame2)
```
# QScrollArea
```python
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
import sys

class window(QMainWindow):
    def __init__(self):
        super(window, self).__init__()
        self.initUI()

    def initUI(self):
        self.main_frame = QWidget(self)
        layout = QHBoxLayout()

        groupBox = self.createParaGroup()
        # s = QScrollArea(self)
        # s.setWidget(groupBox)
        #
        # s.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOn)
        # s.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        # layout.addWidget(s)

        layout.addWidget(groupBox)
        self.main_frame.setLayout(layout)
        self.setCentralWidget(self.main_frame)

    def createParaGroup(self):
        groupBox = QGroupBox('GPS参数')

        # GPS 参数
        self.gps_week_label = QLabel('GPS周：')
        self.gps_week_value_lineedit = QLineEdit()
        self.gps_second_label = QLabel('GPS秒：')
        self.gps_second_value_lineedit = QLineEdit()
        self.gps_sub_label = QLabel('GPS细分时间：')
        self.gps_sub_value_lineedit = QLineEdit()

        self.gps_longitude_label = QLabel('经度：')
        self.gps_longitude_value_lineedit = QLineEdit()
        self.gps_llatitudina_label = QLabel('维度：')
        self.gps_llatitudina_value_lineedit = QLineEdit()
        self.gps_height_label = QLabel('高度：')
        self.gps_height_value_lineedit = QLineEdit()

        self.gps_roll_label = QLabel('翻滚角：')
        self.gps_roll_value_lineedit = QLineEdit()
        self.gps_pitch_label = QLabel('俯仰角：')
        self.gps_pitch_value_lineedit = QLineEdit()
        self.gps_azimuth_label = QLabel('方位角：')
        self.gps_azimuth_value_lineedit = QLineEdit()

        formbox = QFormLayout()
        formbox.addRow(self.gps_week_label, self.gps_week_value_lineedit)
        formbox.addRow(self.gps_second_label, self.gps_second_value_lineedit)
        formbox.addRow(self.gps_sub_label, self.gps_sub_value_lineedit)
        formbox.addRow(self.gps_longitude_label, self.gps_longitude_value_lineedit)
        formbox.addRow(self.gps_llatitudina_label, self.gps_llatitudina_value_lineedit)
        formbox.addRow(self.gps_height_label, self.gps_height_value_lineedit)
        formbox.addRow(self.gps_roll_label, self.gps_roll_value_lineedit)
        formbox.addRow(self.gps_pitch_label, self.gps_pitch_value_lineedit)
        formbox.addRow(self.gps_azimuth_label, self.gps_azimuth_value_lineedit)

        groupBox.setLayout(formbox)

        s = QScrollArea(self)
        s.setWidget(groupBox)
        s.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOn)
        s.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        s.setWidgetResizable(True)
        # 需要返回 QScrollArea, 否则滚动条位置不对
        return s

if __name__ == "__main__":
    app = QApplication(sys.argv)
    ui = window()
    ui.show()
    sys.exit(app.exec_())
```
# 布局
## 1.空白和间距
每种布局有两个重要的属性，空白(margin)和间距(spacing)。
空白指的是整个布局距离窗体边缘的距离。
间距指的是布局管理器内部各个窗口部件的距离。

`setSpaceing()`设置layout里每个控件的空白，缩小窗口时，不能减小这个空白
`addSpaceing()`给此条语句前后的两个控件添加空白，缩小窗口时，不能减小这个空白

```python
layout = QHBoxLayout()

layout.setSpacing(101)
layout.setContentsMargins(left, top, right, bottom) # 设置layout里控件和布局边缘的距离
```

## 2.大小约束（size constraint）

## 3.大小策略（size policy）

## 4.伸缩因子（stretch factor）
默认情况如果将多个控件加入到QT的布局管理器中（QVBoxLayout、QHBoxLayout）所有控件占用的宽度/高度是等比例大小的。
然而，在实际应用和开发中往往希望在同一个布局管理器中，根据控件实际显示内容的多少或大小其相应的比例是不相同的。
这时，可以使用`setStretchFactor`来控制缩放界面时控件的比例
```python
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
import sys

class window(QMainWindow):
    def __init__(self):
        super(window, self).__init__()
        self.initUI()

    def initUI(self):
        self.main_frame = QWidget(self)
        layout = QHBoxLayout()

        tab1 = QTabWidget()
        tab2 = QTabWidget()
        tab1.addTab(QPushButton('btn1'), 'btn1')
        tab1.addTab(QPushButton('btn2'), 'btn2')

        tab2.addTab(QLabel('label1'), 'label1')
        tab2.addTab(QLabel('label2'), 'label2')

        layout.addWidget(tab1)
        layout.addWidget(tab2)

        layout.setStretchFactor(tab1, 1)
        layout.setStretchFactor(tab2, 2)
        self.main_frame.setLayout(layout)
        self.setCentralWidget(self.main_frame)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    ui = window()
    ui.show()
    sys.exit(app.exec_())
```
`addStretch()`在同一个布局的控件间隙里添加弹簧，默认控件之间的弹簧为`addStretch(0)`。只有添加不少于2个弹簧时，拉伸界面，控件的间距才会按照设置的比例变化。
`setStretch()`

## QHBoxLayout 水平布局

```python
hlayout = QHBoxLayout()

hlayout.addWidget( QPushButton(str(1)))
hlayout.addWidget( QPushButton(str(2)))
hlayout.addWidget( QPushButton(str(3)))
hlayout.addWidget( QPushButton(str(4)))
hlayout.addWidget( QPushButton(str(5)))
self.setLayout(hlayout)

```

## QFormLayout 布局

```python
fromlayout = QFormLayout()
labl1 = QLabel("标签1")
lineEdit1 = QLineEdit()
labl2 = QLabel("标签2")
lineEdit2 = QLineEdit()
lineEdit3 = QLineEdit()

fromlayout.addRow(labl1, lineEdit1)
fromlayout.addRow(labl2, lineEdit2)
fromlayout.addRow('标签3', lineEdit3)
		
self.setLayout(fromlayout)   
```

# 信号和槽
信号(Signal)和槽(Slot)是Qt编程中对象间通讯的机制。在Qt中，每一个QObject对象，包括PyQT中所有继承自QWidget的控件(因为它们都是QObject的子对象)都支持signal和slot机制。

```python
self.btn.clicked.connect(self.btn_click)
```
按钮btn被点击（释放clicked信号)时，slot函数（btn_click）会被执行

## 同一signal绑定多slot

PyQt5允许一个signal同时绑定多个slot，如
```python
self.btn.clicked.connect(self.btn_click)
self.btn.clicked.connect(self.btn_click_2)
```
从执行结果上看，slot执行的顺序是跟绑定的顺序一样的，即先绑先执行。另外对于多个signal绑定同一slot的情况，比较容易理解，就不多说

## 一个signal绑定另一个signal

还有种特殊的情况是signal和signal绑定，这里假设还有一个btn1我们让它的clicked信号和btn的信号clicked相绑定，如下
```python
self.btn.clicked.connect(self.btn_click)
self.btn1.clicked.connect(self.btn.clicked)
```

## 自定义信号
新的信号应该定义在QObject的`子类`中（包括QWidget等）。新的信号必须作为定义类的一部分，不允许将信号作为类的属性在类定义之后通过动态的方式进行添加。
通过这种方式新的信号才能自动的添加到QMetaObject类中。这就意味这新定义的信号将会出现在Qt Designer，并且可以通过QMetaObject API实现内省。
 
```python
class CustSignal(QObject):
    # 声明一个无参数的信号
    signal1 = pyqtSignal()
    # 声明带一个int类型参数的信号
    signal2 = pyqtSignal(int)
    # 声明带一个int和str类型参数的信号
    signal3 = pyqtSignal(int,str)
    # 声明带一个列表类型参数的信号
    signal4 = pyqtSignal(list)
    # 声明带一个字典类型参数的信号
    signal5 = pyqtSignal(dict)
    # 声明一个多重载版本的信号，包括了一个带int和str类型参数的信号或着带str参数的信号
    signal6 = pyqtSignal([int,str], [str])

    def __init__(self):
        super(CustSignal, self).__init__()
```
      

## 使用过程
1.在QObject子类里定义信号
```python 
testSignal = pyqtSignal(str)
```

2. 定义并绑定槽函数
```python
self.testSignal[str].connect(self.get_signal)

def get_signal(self, name):
    QMessageBox.warning(self, 'biaoti', name)
```

3. 发射信号
信号要从其他函数发射
```python
def emit_signal(self):
    # 信号发射时，信号连接的槽函数才会工作
    self.testSignal[str].emit('wangjun')
```

# 线程 QThread
Qt 中所有界面都是在 UI 线程中（也被称为主线程，就是执行了QApplication::exec()的线程），在这个线程中执行耗时的操作（比如那个循环），就会阻塞 UI 线程，从而让界面停止响应。

## 继承QThread，重写run方式
```python
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
import  sys

class DemoThread(QThread):
    '''
    重写QThread，在run函数中完成我们所需要的任务
    如果不使用while循环，本线程只执行一次
    while循环一次，可以发送一次带参数的信号，完成线程间通信
    '''
    trigger = pyqtSignal(int)

    def __init__(self):
        super(DemoThread, self).__init__()

    def run(self):
        num = 0
        while(1):
            num = num + 1
            for i in range(10000000):
                pass
            self.trigger.emit(num)

class window(QMainWindow):
    def __init__(self):
        super(window, self).__init__()

        self.test_thread = DemoThread()
        # DemoThread中信号 绑定 到slot上
        self.test_thread.trigger[int].connect(self.change_label)

        self.init_ui()

    def init_ui(self):
        btn = QPushButton('push')
        btn.clicked.connect(self.start_thread)

        self.label = QLabel('11')

        self.main_frame = QWidget()
        top_layout = QVBoxLayout()
        top_layout.addWidget(btn)
        top_layout.addWidget(self.label)
        self.main_frame.setLayout(top_layout)
        self.setCentralWidget(self.main_frame)

    def start_thread(self):
        self.test_thread.start()  # 启动线程

    def change_label(self, num):
        self.label.setText(str(num))

if __name__ == "__main__":
    app = QApplication(sys.argv)
    ui = window()
    ui.show()
    sys.exit(app.exec_())
```

## movetoThread方式一
使用死循环
```python
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
import  sys
import  time

class MyWork(QObject):
    '''
    继承QObject，定义信号以及工作函数work，函数名可以任意
    '''
    trigger = pyqtSignal(int)
    def __init__(self):
        super(MyWork, self).__init__()

    def work(self):
        num = 0
        while True:
            time.sleep(1)
            num = num + 1
            self.trigger.emit(num)

class window(QMainWindow):
    def __init__(self):
        super(window, self).__init__()

        # 实例以及连接signal和slot
        self.obj = MyWork()
        self.obj.trigger[int].connect(self.show_rec)

        # 实例新线程
        self.inc_thread = QThread()
        # 将工作转移到线程里。必须在线程的started信号和工作slot连接之前move，否则会卡死UI线程
        self.obj.moveToThread(self.inc_thread)

        # 将线程启动信号(signal)和逻辑函数(slot)连接到一起
        # 然后其他地方启动线程
        self.inc_thread.started.connect(self.obj.work)

        # 对于单次长时间的工作，可以在工作结束时退出线程
        # self.obj.analyze_done.connect(self.inc_thread.quit)
        self.init_ui()

    def init_ui(self):
        self.btn = QPushButton('push')
        self.text = QTextEdit()

        self.btn.clicked.connect(self.start_thread)

        main_frame = QWidget(self)
        top_lyt = QVBoxLayout(main_frame)
        top_lyt.addWidget(self.btn)
        top_lyt.addWidget(self.text)

        main_frame.setLayout(top_lyt)
        self.setCentralWidget(main_frame)

    def start_thread(self):
        self.inc_thread.start()

    def show_rec(self, num):
        self.text.setText(str(num))


if __name__ == "__main__":
    app = QApplication(sys.argv)
    ui = window()
    ui.show()
    sys.exit(app.exec_())
```

# movetoThread方式二
线程很快打开
```python
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
import  sys
import  datetime
import  time

class MyWork(QObject):
    '''
    继承QObject，定义信号以及工作函数work，函数名可以任意
    '''
    trigger = pyqtSignal(int)
    def __init__(self):
        super(MyWork, self).__init__()
        self.num = 0

    def work(self):
        # while True:
        time.sleep(2)
        self.num = self.num + 1
        print('发射信号时间')
        print(datetime.datetime.now())
        self.trigger.emit(self.num)


class DoWork(QObject):
    def __init__(self):
        super(DoWork, self).__init__()

    def work(self):
        time.sleep(1)
        print('hello world')
        print('Do Work执行时间')
        print(datetime.datetime.now())

class window(QMainWindow):
    ui_signal = pyqtSignal()
    def __init__(self):
        super(window, self).__init__()

        # 实例以及连接signal和slot
        self.my_work = MyWork()
        self.my_work.trigger[int].connect(self.show_rec)

        self.do_work = DoWork()

        # 新线程
        self.inc_thread = QThread()
        # 将工作转移到线程里。必须在程的started信号和工作slot连接之前move，否则会卡死UI线程线
        self.my_work.moveToThread(self.inc_thread)
        self.do_work.moveToThread(self.inc_thread)

        self.inc_thread.start()

        # 当多个函数连接到同一个线程里的时候，如果ui_signal信号发射了，线程里的两个函数按照连接的先后顺序执行
        # 他们在线程里顺序执行
        self.ui_signal.connect(self.my_work.work)
        self.ui_signal.connect(self.do_work.work)

        self.init_ui()

    def init_ui(self):
        self.btn = QPushButton('push')
        self.text = QTextEdit()

        self.btn.clicked.connect(self.start_thread)

        main_frame = QWidget(self)
        top_lyt = QVBoxLayout(main_frame)
        top_lyt.addWidget(self.btn)
        top_lyt.addWidget(self.text)

        main_frame.setLayout(top_lyt)
        self.setCentralWidget(main_frame)

    def start_thread(self):
        self.ui_signal.emit()

    def show_rec(self, num):
        time.sleep(2)
        print('设置数字时间')
        print(datetime.datetime.now())
        self.text.setText(str(num))

if __name__ == "__main__":
    app = QApplication(sys.argv)
    ui = window()
    ui.show()
    sys.exit(app.exec_())

```

# QUdpSocket
```python
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtNetwork import QUdpSocket, QHostAddress
import sys

class UdpRec(QObject):
    trigger = pyqtSignal(str)

    def __init__(self):
        super(UdpRec, self).__init__()

        self.udpSocket = QUdpSocket(self)
        self.udpSocket.bind(QHostAddress.LocalHost, 6666)

    def work(self):
        while True:
            if self.udpSocket.hasPendingDatagrams():
                datagram, host, port = self.udpSocket.readDatagram(self.udpSocket.pendingDatagramSize())
                self.trigger.emit(datagram.decode())
        pass

class window(QMainWindow):
    def __init__(self):
        super(window, self).__init__()

        self.udp_rec_thread = QThread()

        self.udp_rec = UdpRec()
        self.udp_rec.trigger[str].connect(self.show_rec)
        self.udp_rec.moveToThread(self.udp_rec_thread)
        self.udp_rec_thread.started.connect(self.udp_rec.work)

        self.init_ui()

    def init_ui(self):
        self.btn = QPushButton('start receive')
        self.btn.clicked.connect(self.start)

        self.text = QTextEdit()
        self.main_frame = QWidget()
        top_lyt = QVBoxLayout()
        top_lyt.addWidget(self.btn)
        top_lyt.addWidget(self.text)
        self.main_frame.setLayout(top_lyt)
        self.setCentralWidget(self.main_frame)

    def start(self):
        self.udp_rec_thread.start()

    def show_rec(self, name):
        self.text.setText(name)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    ui = window()
    ui.show()
    sys.exit(app.exec_())
```

# Qt和PyQt对应
```c++
QLabel *label = new QLabel(this);
label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
```
```python
label = QLabel('wang')
label.setAlignment(Qt.AlignCenter)  # 设置label内容对齐方式
```

# Event

## 鼠标事件
```python
     def mouseReleaseEvent(self, event):
        print('mouse release')

    def mouseDoubleClickEvent(self, event):
        print('mouse double clicked')

    def mousePressEvent(self, event):
        print('mouse press')

    def mouseMoveEvent(self, event):
        print('mouse move')
```
1. 双击事件会触发两次单击事件   
2. 必须按住鼠标才会触发`mouseMoveEvent()

## 滚轮事件
```python
    def wheelEvent(self, event):
        if event.angleDelta().y() > 0:
            print('up')
        elif event.angleDelta().y() < 0:
            print('down')
```
## closeEvent
```python
def closeEvent(self, event):
        reply = QMessageBox.question(self, 'Message', 'You sure to quit?',
                                     QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if reply == QtGui.QMessageBox.Yes:
            event.accept()
        else:
            event.ignore()
```

## paintEvent
QPainter的常见用法是在widget的绘制事件中：构造和自定义（例如设置笔或画笔）画家。然后画画。记得在绘图后销毁QPainter对象。例如：

```python
from PyQt5.QtGui import QPainter, QColor, QFont
from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication, QWidget

class PyQt5_Paint(QWidget):
    def __init__(self):
        super(PyQt5_Paint, self).__init__()
        self.initUI()

    def initUI(self):
        self.setWindowTitle('PyQt5_Temp')

    def paintEvent(self, event):
        qp = QPainter()
        qp.begin(self)
        qp.setFont(QFont("Arial", 30))
        qp.setPen(QColor(162, 39, 43))
        qp.drawText(event.rect(), Qt.AlignCenter, 'Qt')
        qp.end()


if __name__ == '__main__':
    import sys
    app = QApplication(sys.argv)

    ui = PyQt5_Paint()
    ui.show()
    sys.exit(app.exec_())
```
### 画直线
```python
p.drawLine( QRect(50, 100, 300, 200).topLeft(),  QRect(50, 100, 300, 200).topRight())
p.drawLine(QLine(10, 10, 30, 30))
```

### 画矩形
```python
p.setBrush(QColor(88, 99, 100))
# setBrush设置填充区域颜色
p.drawRect(QRect(50, 100, 300, 200))
```

### 绘制圆角矩形
```python
p.setBrush(QColor(88, 99, 100))
# setBrush设置填充区域颜色
p.drawRoundedRect(QRect(50, 100, 300, 200), 20, 20, Qt.RelativeSize)
```

### 绘制椭圆
```python
 p.drawEllipse(QRect(150, 200, 300, 200))
 ```

### 绘制多边形
```python
points = [QPoint(150, 100), QPoint(300, 150), QPoint(350, 250), QPoint(100, 300)]
p.drawPolygon(QPolygon(points), Qt.WindingFill)
```

### 绘制折线
```python
points = [QPoint(150, 100), QPoint(300, 150), QPoint(350, 250), QPoint(100, 300)]
p.drawPolyline(QPolygon(points))
```

### 绘制饼状
```python
p.drawPie(QRect(100, 150, 300, 200), 30*2, 120*16)
```

## 事件过滤
```python
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
import sys


class window(QMainWindow):
    def __init__(self):
        super(window, self).__init__()
        self.initUI()

    def initUI(self):
        self.main_frame = QWidget(self)

        self.line1 = QLineEdit('nihao')
        self.line2 = QLabel('hello')
        self.line1.installEventFilter(self)
        self.line2.installEventFilter(self)
        layout = QVBoxLayout()

        layout.addWidget(self.line1)
        layout.addWidget(self.line2)

        self.main_frame.setLayout(layout)
        self.setCentralWidget(self.main_frame)

    def eventFilter(self, watched, event):
        # if watched == self.line1:
        #     if event.type() == QEvent.MouseButtonPress:
        #         mouseEvent = QMouseEvent(event)
        #         if mouseEvent.buttons() == Qt.LeftButton:
        #             self.line2.setText('enter')
        #
        #     if event.type() == QEvent.MouseButtonRelease:
        #         self.line2.setText('release')
        # return QMainWindow.eventFilter(self, watched, event)

        # if event.type() == QEvent.MouseButtonPress:
        if event.type() == QEvent.KeyPress:
            print(watched)
            if watched == self.line1:
                keyEvent = QKeyEvent(event)
                if keyEvent.key() == Qt.Key_Return:
                    self.line2.setText('enter')
        # 必须有这句 
        return QMainWindow.eventFilter(self, watched, event)
        pass
if __name__ == "__main__":
    app = QApplication(sys.argv)
    ui = window()
    ui.show()
    sys.exit(app.exec_())
```

# QtChart

## 折线图
```python
import random
from PyQt5.QtChart import QChart, QLineSeries, QChartView, QValueAxis
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *
import datetime

class Chart(QWidget):
    def __init__(self):
        super(Chart, self).__init__()
        self.initUI()

    def initUI(self):
        vbox = QVBoxLayout()
        vbox.addWidget(self.chartUI())
        vbox.addWidget(self.controlUI())

        self.setLayout(vbox)

    def chartUI(self):
        self.chart1 = QLineSeries()
        self.chart1.setName('chart1')

        #pen = QPen()
        # pen.setWidthF(.2)
        #pen.setColor(Qt.red)
        #self.chart1.setPen(pen)
        self.chart1.setPen(QPen(Qt.yellow))

        self.chart = QChart()
        # self.chart.legend().hide()
        self.chart.addSeries(self.chart1)
        self.chart.setAnimationOptions(QChart.AllAnimations)
        self.chart.setTitle("basic class")

        self.axis_x = QValueAxis()
        self.axis_y = QValueAxis()
        self.chart.setAxisX(self.axis_x, self.chart1)
        self.chart.setAxisY(self.axis_y, self.chart1)

        self.chartView = QChartView()
        self.chartView.setChart(self.chart)
        self.chartView.setRubberBand(QChartView.RectangleRubberBand)
        self.chartView.setRenderHint(QPainter.Antialiasing)

        return self.chartView

    def controlUI(self):
        self.ch0Enable = QCheckBox('Ch0 Enable')
        self.ch0Enable.setChecked(True)
        hbox1 = QHBoxLayout()
        hbox1.addWidget(self.ch0Enable)
        hbox1.addStretch(1)

        self.xDataMinLabel = QLabel('x min:')
        self.xDataMaxLabel = QLabel('x max:')
        self.yDataMinLabel = QLabel('y min:')
        self.yDataMaxLabel = QLabel('y max:')

        self.xDataMinLine = QLineEdit()
        self.xDataMaxLine = QLineEdit()
        self.yDataMinLine = QLineEdit()
        self.yDataMaxLine = QLineEdit()
        self.setBtn = QPushButton('设置')

        hbox = QHBoxLayout()
        hbox.addWidget(self.xDataMinLabel)
        hbox.addWidget(self.xDataMinLine)
        hbox.addWidget(self.xDataMaxLabel)
        hbox.addWidget(self.xDataMaxLine)
        hbox.addWidget(self.yDataMinLabel)
        hbox.addWidget(self.yDataMinLine)
        hbox.addWidget(self.yDataMaxLabel)
        hbox.addWidget(self.yDataMaxLine)
        hbox.addWidget(self.setBtn)

        mainLayout = QVBoxLayout()
        mainLayout.addLayout(hbox1)
        mainLayout.addLayout(hbox)
        frame = QFrame()
        frame.setLayout(mainLayout)

        self.setBtn.clicked.connect(self.setAxisRange)
        return frame

    def update(self, xData, yData):
        '''
        :param xData: list, store x coordinate data
        :param yData: list, store y coordinate data
        :return:
        '''

        self.chart1.clear()
        self.axis_x.setRange(min(xData)- max(xData)//10, max(xData)*11//10)
        self.axis_y.setRange(min(yData)- max(yData)//10, max(yData)*11//10)
        print(datetime.datetime.now())
        for i in range(0, len(xData)):
            if self.ch0Enable.isChecked():
                # self.chart1.append(QPoint(xData[i], yData[i]))
                self.chart1.append(xData[i], yData[i])
        print(datetime.datetime.now())

        self.chart1.clear()
        print(datetime.datetime.now())
        for i in range(0, len(xData)):
            if self.ch0Enable.isChecked():
                self.chart1.append(QPoint(xData[i], yData[i]))
        print(datetime.datetime.now())
        self.chartView.update()

    @pyqtSlot()
    # def setAxisRange(self, xDataMin, xDataMax, yDataMin, yDataMax):
    #     self.axis_x.setRange(xDataMin, xDataMax)
    #     self.axis_y.setRange(yDataMin, yDataMax)
    def setAxisRange(self):
        self.axis_x.setRange(int(self.xDataMinLine.text()), int(self.xDataMaxLine.text()))
        self.axis_y.setRange(int(self.yDataMinLine.text()), int(self.yDataMaxLine.text()))


class TestUi(QWidget):
    def __init__(self):
        super(TestUi, self).__init__()

        self.chart = Chart()
        self.btn = QPushButton('push')

        self.btn.clicked.connect(self.generateData)

        vbox = QVBoxLayout()
        vbox.addWidget(self.chart)
        vbox.addWidget(self.btn)

        self.setLayout(vbox)

    def generateData(self):
        x = []
        y = []
        for i in range(0, 1000):
            x.append(i)
            y.append(random.randint(0, 100))

        self.chart.update(x, y)

if __name__ == "__main__":
    import sys

    app = QApplication([sys.argv])
    graph = TestUi()
    graph.show()

    sys.exit(app.exec_())
```