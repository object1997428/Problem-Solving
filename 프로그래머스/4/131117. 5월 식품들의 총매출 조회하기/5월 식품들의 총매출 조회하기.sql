-- 코드를 입력하세요


select a.PRODUCT_ID, PRODUCT_NAME, PRICE*b.AMOUNT as TOTAL_SALES
from FOOD_PRODUCT a
join (
    SELECT PRODUCT_ID, sum(AMOUNT) as AMOUNT
    from FOOD_ORDER
    where year(PRODUCE_DATE)=2022 and month(PRODUCE_DATE)=5
    group by PRODUCT_ID
) b on a.PRODUCT_ID=b.PRODUCT_ID
order by TOTAL_SALES desc, a.PRODUCT_ID