#!/usr/bin/env python3
# merge_logs.py
# Gộp nội dung logs_new.txt vào cuối logs.txt

import os
import sys

def merge_logs(logs='logs.txt', new_logs='logs_new.txt'):
    # Kiểm tra file nguồn có tồn tại không
    if not os.path.exists(new_logs):
        return

    # Mở logs.txt ở chế độ append và logs_new.txt để đọc
    with open(logs, 'a', encoding='utf-8') as fout, \
         open(new_logs, 'r', encoding='utf-8') as fin:
        for line in fin:
            fout.write(line)


if __name__ == '__main__':
    merge_logs()
