-- 코드를 입력하세요
SELECT b.TITLE, b.BOARD_ID, r.REPLY_ID, r.WRITER_ID, r.CONTENTS, date_format(r.CREATED_DATE,'%Y-%m-%d') as CREATED_DATE
from USED_GOODS_BOARD b
right join USED_GOODS_REPLY r
on b.BOARD_ID=r.BOARD_ID
where year(b.CREATED_DATE)=2022 and month(b.CREATED_DATE)=10
order by r.CREATED_DATE, b.TITLE;