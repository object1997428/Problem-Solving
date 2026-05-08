# -- 코드를 입력하세요
# SELECT distinct(CAR_ID)
# from CAR_RENTAL_COMPANY_RENTAL_HISTORY
# where month(START_DATE)=10

# SELECT *
# from CAR_RENTAL_COMPANY_RENTAL_HISTORY
# where month(START_DATE)=10
# order by car_id desc;

select distinct(CAR_ID)
from CAR_RENTAL_COMPANY_CAR
where CAR_ID in (
    SELECT CAR_ID
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where month(START_DATE)=10
) and CAR_TYPE ='세단'
order by CAR_ID desc;