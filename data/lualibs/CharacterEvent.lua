CharacterEvent = {}

CharacterEvent.new = function(eventName)
	local initCharacter = function(self)
		self.character = MapManager.currentMap:getEvent(eventName)
		
		self.update = function() end
		
		self.render = function()
			self.character:render()
		end
		
		return self
	end
	
	return {initCharacter = initCharacter}
end

