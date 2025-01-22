-- 코드를 작성해주세요


select a.ITEM_ID, a.ITEM_NAME
from ITEM_INFO a
join (
    select ITEM_ID
    from ITEM_TREE b
    where PARENT_ITEM_ID is null
) as b on a.ITEM_ID=b.ITEM_ID
order by a.ITEM_ID;