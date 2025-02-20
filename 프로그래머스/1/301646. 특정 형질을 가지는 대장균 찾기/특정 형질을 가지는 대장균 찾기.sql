select count(1) as COUNT
from ECOLI_DATA a
where !(GENOTYPE&2) and ((GENOTYPE&1)or(GENOTYPE&4))