pub struct Ram{
   pub frame_count : i32,
   pub page_faults : mut i32,
   pub size : i32,
   pub frames : mut Vec<i32>,
}

impl Ram{
    pub fn new(frame_count: i32, size: i32) -> Result<Ram, &'static str>{
        if(frame_count < 1 || size < 1){
            return Err("Invalid Ram creation instructions");
        }
        let mut ram = Ram{
            frame_count: frame_count,
            page_faults: 0,
            size: size,
            frames: Vec::new()
        }
        Ok(ram)
    }
    pub fn contains(&self, page: &i32) -> bool{
        if(self.frames.contains(&page)){
            return true;
        }
        false
    }
    pub fn insert(&self, page: &i32){
        if(!self.frames.contains(&page)){
            self.frames.push(page);
            self.page_faults += 1;
        }else if(self.frames){
            
        }
    }
}
