select c.ITEM_ID, c.ITEM_NAME, c.RARITY
from ITEM_INFO c
join (
    select b.ITEM_ID as CID
    from ITEM_INFO a
    join ITEM_TREE b on b.PARENT_ITEM_ID=a.ITEM_ID
    where a.RARITY='RARE'
) d on c.ITEM_ID=CID
order by c.ITEM_ID desc;