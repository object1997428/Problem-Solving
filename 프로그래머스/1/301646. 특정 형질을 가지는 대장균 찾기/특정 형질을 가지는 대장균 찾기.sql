-- 코드를 작성해주세요
select count(1) as COUNT
from ECOLI_DATA a
where ((GENOTYPE&1) or (GENOTYPE&4)) and !(GENOTYPE&2)