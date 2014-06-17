LuaEvent = {
	new = function(eventName)
		local initEvent = function(self)
			self.event = MapManager.currentMap:getEvent(eventName)
			
			self.update = function() end
			
			self.render = function()
				self.event:render()
			end
			
			return self
		end
		
		return {initEvent = initEvent}
	end
}

