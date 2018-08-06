# QSplitter
分割窗口类。

QSplitter里无法添加Layout对象，只能添加Widget对象
```python
        # 1. 声明
        top_splitter = QSplitter(Qt.Horizontal)
        # 2. 将布局好的Layout对象添加到QFrame里
        frame1 = QFrame()
        frame1.setLayout(left_vlyt)
        frame2 = QFrame()
        frame2.setLayout(right_vlyt)
        # 3. 添加QFrame，这样水平布置的两个布局就可以左右拉动大小了
        top_splitter.addWidget(frame1)
        top_splitter.addWidget(frame2)
```