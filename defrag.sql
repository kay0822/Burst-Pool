select blockID into @blockID from Blocks order by blockID desc limit 1;
delete from Nonces where blockID<(@blockID-1000) and is_blocks_best_deadline=false;
optimize table Nonces;
delete from Shares where blockID<(@blockID-1000);
optimize table Shares;
optimize table Rewards;
show table status;
