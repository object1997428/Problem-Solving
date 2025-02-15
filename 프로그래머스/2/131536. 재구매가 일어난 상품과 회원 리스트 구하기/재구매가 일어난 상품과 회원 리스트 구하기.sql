-- 코드를 입력하세요
SELECT USER_ID, PRODUCT_ID
from ONLINE_SALE a
group by USER_ID, PRODUCT_ID
having count(1)>1
order by USER_ID asc, PRODUCT_ID desc;

# SELECT USER_ID, PRODUCT_ID
# from ONLINE_SALE a
# order by USER_ID asc, PRODUCT_ID desc;