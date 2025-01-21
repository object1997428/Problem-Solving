-- 코드를 입력하세요
SELECT (a.PRICE div 10000)*10000 as PRICE_GROUP, count(a.PRODUCT_ID) as PRODUCTS
from PRODUCT a
group by PRICE_GROUP
order by PRICE_GROUP;