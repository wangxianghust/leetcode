#打印file.txt的前10行
cnt=0
while read line && [ $cnt -le 10 ]; do
    let 'cnt = cnt + 1'
    if [ $cnt -eq 10 ]; then 
        echo $line
        exit 0
    fi
done < file.txt

#Solution2
awk 'FNR == 10 {print }' file.txt
