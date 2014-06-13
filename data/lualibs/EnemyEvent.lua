EnemyEvent = {}

EnemyEvent.new = function(eventName, troopID, atCollision)
	local initCharacter = function(self)
		self.character = MapManager.currentMap:getEvent(eventName)
		
		self.atCollision = atCollision
		
		self.update = function() end
		
		self.render = function()
			self.character:render()
		end
		
		self.action = function()
			if not self.atCollision and Keyboard.isKeyPressedOnce(Keyboard.GameAttack) then
				ActivityManager.startBattle(troopID)
			end
		end
		
		self.collisionAction = function()
			if self.atCollision then
				ActivityManager.startBattle(troopID)
			end
		end
		
		return self
	end
	
	return {initCharacter = initCharacter}
end

