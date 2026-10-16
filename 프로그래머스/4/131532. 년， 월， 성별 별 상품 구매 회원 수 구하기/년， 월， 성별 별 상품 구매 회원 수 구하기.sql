select year(SALES_DATE) YEAR, month(SALES_DATE) MONTH, GENDER, count(distinct UI.USER_ID) USERS
from ONLINE_SALE OS
join USER_INFO UI on OS.USER_ID=UI.USER_ID
where GENDER is not null
group by year(SALES_DATE), month(SALES_DATE), GENDER
order by year(SALES_DATE), month(SALES_DATE), GENDER;
