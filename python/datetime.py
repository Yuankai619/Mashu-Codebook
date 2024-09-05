from datetime import datetime, date, time, timedelta

# 閏年 2024
# 平年 2023

# 日期相減
start_time = datetime(2024, 8, 31)
end_time = datetime(2024, 9, 1)
delta = end_time - start_time
print(delta.days)
# 1

# 時間相減
start_time = datetime(1000, 1, 1, 14, 30)
end_time = datetime(1000, 1, 1, 16, 50)
delta = end_time - start_time
print(delta) # 2:20:00
print(delta.total_seconds()) # 8400.0


# 時間日期相加
specific_date = datetime(1000, 1, 1)
new_date = specific_date + timedelta(days=3, hours=1, minutes=1)
print(new_date)
# 1000-01-04 01:01:00
print(new_date.year, new_date.month, new_date.day, new_date.hour, new_date.minute, new_date.second)
# 1000 1 4 1 1 0