# 概述
1. 使用了很多的事件过滤程序，程序性能会下降

# 鼠标

## 鼠标事件
1. mousePressEvent(self, event) 鼠标键按下时调用
2. mouseReleaseEvent(self, event) 鼠标键松开时调用
3. mouseDoubleClickEvent(self, event) 双击鼠标时调用
4. wheelEvent(self, event) 处理鼠标滚动

```python
import sys
from PyQt5.QtCore import Qt, QPointF, pyqtSignal
from PyQt5.QtGui import QPainter, QPolygonF
from PyQt5.QtWidgets import QWidget, QApplication, QMessageBox

class Demo(QWidget):
    """
    相关API测试
    """
    def __init__(self):
        super(Demo, self).__init__()
    
    def initUI(self):
        pass
    
    def mousePressEvent(self, event):
        QWidget.mousePressEvent(self, event)
        print(event.button())           # 
        print(event.x())                # 鼠标按下是的x坐标
        print(event.y())                # 鼠标按下时的y坐标
        print(event.pos())
        print(event.localPos())         # 鼠标按下时坐标的浮点精度表示

        print(event.globalPos())        # 相对于屏幕的鼠标 坐标
        print(event.timestamp())

if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = Demo()
    window.show()
    sys.exit(app.exec_())
```

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

# 按键事件

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