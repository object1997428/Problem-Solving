-- 코드를 작성해주세요
select count(1) as FISH_COUNT
from FISH_INFO a
where FISH_TYPE in (
    select FISH_TYPE
    from FISH_NAME_INFO b
    where FISH_NAME = "BASS" or FISH_NAME = "SNAPPER"
)