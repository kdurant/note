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
