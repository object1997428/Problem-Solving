-- 코드를 작성해주세요

select round(sum(c.LEN)/count(a.ID),2) as AVERAGE_LENGTH
from FISH_INFO a
left join (
    select
        case when (b.LENGTH is null) then 10
            else b.LENGTH
        end as LEN,
        b.ID
    from FISH_INFO b
) c
on a.ID=c.ID

;