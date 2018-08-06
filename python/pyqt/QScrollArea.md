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