CharacterEvent = {}

CharacterEvent.new = function(eventName)
	local initCharacter = function(self)
		self.character = MapManager.currentMap:getEvent(eventName)
		
		self.update = function() end
		
		self.render = function()
			self.character:render()
		end
		
		self.actions = function() end
		
		self.action = function()
			if Keyboard.isKeyPressedOnce(Keyboard.GameAttack) then
				self.character:setDirection(3 - CharacterManager.player():getDirection())
				
				self.render() -- Update the Character direction in screenshot
				
				self.actions()
			end
		end
		
		self.collisionAction = function() end
		
		return self
	end
	
	return {initCharacter = initCharacter}
end

