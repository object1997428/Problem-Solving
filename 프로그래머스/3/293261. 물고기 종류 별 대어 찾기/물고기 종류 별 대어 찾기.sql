

select a.ID, c.FISH_NAME, b.LENGTH
from FISH_INFO a
join (
    select FISH_TYPE, max(LENGTH) as LENGTH
    from FISH_INFO a
    group by FISH_TYPE
) as b on a.FISH_TYPE=b.FISH_TYPE and a.LENGTH=b.LENGTH
join FISH_NAME_INFO c
on a.FISH_TYPE=c.FISH_TYPE
order by a.ID