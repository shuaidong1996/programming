package com.dong.dongblog.dto;

public class ResponseUserDto extends ResponseCommonDto {
    private UserDto user;

    public UserDto getUser() {
        return user;
    }

    public void setUser(UserDto user) {
        this.user = user;
    }
}
