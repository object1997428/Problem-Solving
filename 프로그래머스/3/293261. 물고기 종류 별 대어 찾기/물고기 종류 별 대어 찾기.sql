

select ID, FISH_NAME, LENGTH
from FISH_INFO a
join (
    select FISH_TYPE, max(LENGTH) as ML
    from FISH_INFO
    group by FISH_TYPE
)as b on a.FISH_TYPE=b.FISH_TYPE
join FISH_NAME_INFO c on a.FISH_TYPE=c.FISH_TYPE
where LENGTH=ML
order by ID;