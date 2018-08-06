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
