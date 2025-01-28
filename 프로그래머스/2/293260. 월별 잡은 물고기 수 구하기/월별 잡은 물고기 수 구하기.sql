-- 코드를 작성해주세요

select count(ID) as FISH_COUNT, month(TIME) as MONTH
from FISH_INFO a
group by month(TIME)
order by MONTH;