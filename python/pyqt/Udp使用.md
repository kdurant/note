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