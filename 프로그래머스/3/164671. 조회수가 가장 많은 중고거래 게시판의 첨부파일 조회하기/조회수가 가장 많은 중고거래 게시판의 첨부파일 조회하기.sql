select concat("/home/grep/src/", a.BOARD_ID,"/",a.FILE_ID,a.FILE_NAME,a.FILE_EXT) as FILE_PATH
from USED_GOODS_FILE a
join (
    select BOARD_ID
    from USED_GOODS_BOARD b
    order by b.VIEWS desc
    limit 1
) b on a.BOARD_ID=b.BOARD_ID
order by a.FILE_ID desc;