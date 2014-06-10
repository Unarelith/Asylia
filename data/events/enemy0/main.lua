enemy0 = EnemyEvent.new("enemy0", 0)

enemy0.init = function()
	enemy0 = enemy0:initCharacter();
	
	enemy0.character:setHitbox(8, 8, 64, 64);
	enemy0.character:setPosition(enemy0.character:x() - 8, enemy0.character:y() - 8);
	
	enemy0.movements = {
		function() enemy0.character:moveLeft() end,
		function() enemy0.character:moveUp() end,
		function() enemy0.character:moveRight() end,
		function() enemy0.character:moveDown() end
	}
end

