# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{ print $2, $1}'

# tr, 替换
# sort 排序
# uniq -c 统计重复行
# sort -r 逆序
# awk 输出， $1, $2 分别表示第一个和第二个字段