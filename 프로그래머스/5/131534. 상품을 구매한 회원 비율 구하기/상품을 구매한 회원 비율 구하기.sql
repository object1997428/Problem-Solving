with tmp  as (
    select USER_ID
    from USER_INFO
    where year(JOINED)=2021
)


select 
year(SALES_DATE) as YEAR,
month(SALES_DATE) as MONTH,
count(distinct A.USER_ID) as `PURCHASED_USERS`,
round(count(distinct A.USER_ID) /
(select count(*) from USER_INFO where year(JOINED)=2021),1) as `PUCHASED_RATIO`
from ONLINE_SALE A
join tmp on tmp.USER_ID=A.USER_ID
group by year(SALES_DATE),month(SALES_DATE)
order by YEAR, MONTH