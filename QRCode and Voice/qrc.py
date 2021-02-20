# This Python file uses the following encoding: utf-8

import qrcode
from qrcode.image.pure import PymagingImage
import qrcode.image.svg


def qr(txt):
    mydata = qrcode.QRCode(version=1, border=2, box_size=5)
    mydata.add_data(txt)
    mydata.make(fit=True)
    my_img = mydata.make_image(fill_color='black', back_color='white')
    
    return my_img
