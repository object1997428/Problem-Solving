select CAR_ID,
case
when car_id in (
    SELECT car_id
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY h
    where '2022-10-16'<= END_DATE and START_DATE <= '2022-10-16'
    group by CAR_ID
) then "대여중"
else "대여 가능" 
end as AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY h
group by CAR_ID
order by CAR_ID desc;