cat > grt4.txt
echo showing_file........
cat grt4.txt

echo total no students
wc -l grt4.txt

echo displaying all roll numbers
cut -d" " -f2 grt4.txt  
