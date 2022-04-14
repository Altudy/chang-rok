package com.kdis.demo.vo;

public class ReserveDto {

	// reservation
	private int reservation_id;

	private String cancel_flag;

	private String discount;

	// reservation_info
	private  String user_id;
	private String title;
	private String movieAge;
	private String selectedTheater;
	private String movieDate;
	private String runningTime;
	private int payMoney;
	private String selectedSeat;
	
	public ReserveDto() {
		super();
	}

	public ReserveDto(String title, String movieAge, String selectedTheater, String movieDate, String runningTime,
			String reserveDate, int payMoney, String selectedSeat) {
		super();
		this.title = title;
		this.movieAge = movieAge;
		this.selectedTheater = selectedTheater;
		this.movieDate = movieDate;
		this.runningTime = runningTime;
		this.payMoney = payMoney;
		this.selectedSeat = selectedSeat;
	}

	public int getReservation_id() {
		return reservation_id;
	}

	public void setReservation_id(int reservation_id) {
		this.reservation_id = reservation_id;
	}

	public String getDiscount() {
		return discount;
	}

	public void setDiscount(String discount) {
		this.discount = discount;
	}

	public String getCancel_flag() {
		return cancel_flag;
	}

	public void setCancel_flag(String cancel_flag) {
		this.cancel_flag = cancel_flag;
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public String getMovieAge() {
		return movieAge;
	}

	public void setMovieAge(String movieAge) {
		this.movieAge = movieAge;
	}

	public String getSelectedTheater() {
		return selectedTheater;
	}

	public void setSelectedTheater(String selectedTheater) {
		this.selectedTheater = selectedTheater;
	}

	public String getMovieDate() {
		return movieDate;
	}

	public void setMovieDate(String movieDate) {
		this.movieDate = movieDate;
	}

	public String getRunningTime() {
		return runningTime;
	}

	public void setRunningTime(String runningTime) {
		this.runningTime = runningTime;
	}

	public int getPayMoney() {
		return payMoney;
	}

	public void setPayMoney(int payMoney) {
		this.payMoney = payMoney;
	}

	public String getSelectedSeat() {
		return selectedSeat;
	}

	public void setSelectedSeat(String selectedSeat) {
		this.selectedSeat = selectedSeat;
	}

	@Override
	public String toString() {
		return "ReserveDto [title=" + title + ", movieAge=" + movieAge + ", selectedTheater=" + selectedTheater
				+ ", movieDate=" + movieDate + ", runningTime=" + runningTime
				+ ", payMoney=" + payMoney + ", selectedSeat=" + selectedSeat + "]";
	}
}
