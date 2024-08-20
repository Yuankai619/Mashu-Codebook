# 轉為高精度整數比，(分子, 分母)
x=0.2
x.as_integer_ratio()  # (8106479329266893, 9007199254740992)
x.is_integer()        # 判斷是否為整數
x.__round__()         # 四捨五入
int(eval(num.replace("/","//"))) # parser string num