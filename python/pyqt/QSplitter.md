# QSplitter
分割窗口类。QSplitter里无法添加`QLayout`对象，只能添加`QWidget`对象
```python
from PyQt5.QtWidgets import  QWidget, QFrame, QPushButton, QApplication, QVBoxLayout, QSplitter, QTextEdit
from PyQt5.QtCore import Qt

class TOP(QWidget):
    def __init__(self):
        super(TOP, self).__init__()
        self.initUI()
    
    def initUI(self):
        # 1. 声明
        splitter = QSplitter(Qt.Vertical)
        splitter.setStyleSheet("QSplitter::handle { background-color: black }")
        splitter.setHandleWidth(10)
        splitter.addWidget(QTextEdit('333'))
        splitter.addWidget(QTextEdit('222'))
        
        mainLayout = QVBoxLayout()
        mainLayout.addWidget(splitter)
        self.setLayout(mainLayout)

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)
    ui = TOP()
    ui.show()
    sys.exit(app.exec_())
```