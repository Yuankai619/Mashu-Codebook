import re

# \d  0~9
# \D  非0~9
# \s  空白字符
# \S  非空白字符
# ^   開頭
# $   結尾
# re*   0個或多個
# re+   1個或多個
# re?   0個或1個
# re{n} 恰好n次

s = 'a1bb2c2'
print(re.search(r'(?<=\d)[a-z](?=\d)', s).group())
# b
# 匹配前面和後面都要是數字的a~z字元

s = 'a1a a2b b3b'
print(re.search(r'(?<!a)\d(?!a)', s).group())
# 3
# 匹配前後都不是a的數字

s = 'aBc'
print(re.search(r'abc', s, re.I).group())
# aBc
# re.I 忽略大小寫
# re.S 任意字符 . 不受換行(\n)和空白限制

s = 'abbbbb'
print(re.search(r'ab+?', s).group())
# ab
# 非貪婪用法，匹配ab+但長度越短越好

s = 'abcde'
print(re.findall(r'[a-z]', s))
# ['a', 'b', 'c', 'd', 'e']

s = 'abbbba'
print(re.sub('(?<=a).*(?=a)', '', s))
# aa
# 把.*的部分替換成空字串