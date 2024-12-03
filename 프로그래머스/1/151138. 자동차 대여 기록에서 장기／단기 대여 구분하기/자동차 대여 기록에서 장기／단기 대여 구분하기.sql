-- 코드를 입력하세요
SELECT HISTORY_ID, CAR_ID, date_format(start_date,'%Y-%m-%d') START_DATE, date_format(end_date,'%Y-%m-%d') END_DATE

,case 
when (datediff(end_date,start_date)>=29) then '장기 대여'
else '단기 대여'
end
as RENT_TYPE
from CAR_RENTAL_COMPANY_RENTAL_HISTORY c
where year(START_DATE)=2022 and month(START_DATE)=9
order by HISTORY_ID desc
;