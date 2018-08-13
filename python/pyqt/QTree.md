有两个相关的类
1. QTreeWidget, 带有默认模型的QTreeView
2. QTreeView

# QTreeWidget
```python
from PyQt5.QtWidgets import *

class TreeWidgetDemo(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)

        self.setWindowTitle('TreeWidget Demo')

        hbox = QHBoxLayout()
        addBtn = QPushButton('添加节点')
        updateBtn = QPushButton('修改节点')
        delBtn = QPushButton('删除节点')
        hbox.addWidget(addBtn)
        hbox.addWidget(updateBtn)
        hbox.addWidget(delBtn)

        addBtn.clicked.connect(self.addTreeNodeBtn)
        updateBtn.clicked.connect(self.updateTreeNodeBtn)
        delBtn.clicked.connect(self.delTreeNodeBtn)

        self.tree = QTreeWidget(self)
        self.tree.setColumnCount(2)
        self.tree.setHeaderLabels(['Key', 'Value'])

        root = QTreeWidgetItem(self.tree)
        root.setText(0, 'root')
        root.setText(1, '0')

        child1 = QTreeWidgetItem(root)
        child1.setText(0, 'child1')
        child1.setText(1, '1')

        child2 = QTreeWidgetItem(root)
        child2.setText(0, 'child2')
        child2.setText(1, '2')

        child3 = QTreeWidgetItem(root)
        child3.setText(0, 'child3')
        child3.setText(1, '3')

        child4 = QTreeWidgetItem(child3)
        child4.setText(0, 'child4')
        child4.setText(1, '4')

        child5 = QTreeWidgetItem(child3)
        child5.setText(0, 'child5')
        child5.setText(1, '5')

        self.tree.addTopLevelItem(root)
        self.tree.clicked.connect(self.onTreeClicked)

        mainLayout = QVBoxLayout(self)
        mainLayout.addLayout(hbox)
        mainLayout.addWidget(self.tree)
        self.setLayout(mainLayout)

    def onTreeClicked(self, qmodelindex):
        item = self.tree.currentItem()
        print('key = %s, value = %s' % (item.text(0), item.text(1)))

    def addTreeNodeBtn(self):
        item = self.tree.currentItem()
        node = QTreeWidgetItem(item)
        node.setText(0, 'newNode')
        node.setText(1, '10')

    def updateTreeNodeBtn(self):
        item = self.tree.currentItem()
        item.setText(0, 'UpdateNode')
        item.setText(1, '20')

    def delTreeNodeBtn(self):
        item = self.tree.currentItem()
        root = self.tree.invisibleRootItem()
        for item in self.tree.SelectItems():
            (item.parent() or root).removeChild(item)

if __name__ == '__main__':
    import sys
    app = QApplication(sys.argv)
    tree = TreeWidgetDemo()
    tree.show()
    sys.exit(app.exec_())
```

# QTreeView
QTreeView类提供树视图的默认模型/视图实现。
QTreeView实现模型中项目的树表示。 此类用于提供先前由QListView类提供的标准层次结构列表，但使用Qt的模型/视图体系结构提供的更灵活的方法。