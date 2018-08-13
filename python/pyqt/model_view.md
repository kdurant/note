# [概述](http://www.codebelief.com/article/2017/04/qt-model-view-tutorial/)
关于视图模型，Qt已经封装了几个方便我们使用的类：QListWidget、QTreeWidget和QTabWidget，这几个类特点是使用起来很方便，适合显示比较简单的数据，若是涉及到大量的数据要显示、以及对性能要求严格就得用到视图模型了。
[Model/View框架](http://blog.51cto.com/9291927/1879117)

# [QStandardItemModel](https://www.zhaokeli.com/article/7986.html)
模型提供数据，视图展示数据。所以数据及数据的相关信息（如文本大小、颜色、数据类型等）由模型类（QStandardItemModel）管理，数据的显示（如表格是否可以编辑、选择方式、行列的大小策略等）由视图类（QTableView）管理。
1. 创建模型对象
2. 设置模型元素
3. 显示模型

```python
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *

class myDialog(QDialog):
    def __init__(self, arg=None):
        super().__init__(arg)
        # self.setWindowFlags(Qt.WindowMaximizeButtonHint | Qt.WindowMinimizeButtonHint | Qt.WindowCloseButtonHint)
        self.resize(500, 300)

        self.model = QStandardItemModel(4, 4)
        self.model.setHorizontalHeaderLabels(['r1', 'r2', 'r3', 'r4'])

        for row in range(0, 4):
            for column in range(4):
                item = QStandardItem("row %s, column %s" % (row, column))
                # item = QStandardItem("row %s, column %s" % (row, column))
                self.model.setItem(row, column, item)

        self.tabView = QTableView()   # QTabWidget 是一个带有默认模型的QTableView
        self.tabView.setModel(self.model)
        layout = QVBoxLayout()
        layout.addWidget(self.tabView)
        self.setLayout(layout)
if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)
    dlg = myDialog()
    dlg.show()
    sys.exit(app.exec_())
```