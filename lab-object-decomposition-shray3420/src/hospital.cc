#include "hospital.hpp"

#include "appointment.hpp"
#include "doctor.hpp"
#include "schedule.hpp"
Doctor* Hospital::GetAvailableDoctor(TimeSlot time) {
  for (Doctor* d : doctors_) {
    if (d->IsAvailable(time)) {
      return d;
    }
  }

  return nullptr;
}

void Hospital::AddDoctor(Doctor& d) { doctors_.push_back(&d); }
void Hospital::AddAppointment(TimeSlot time, std::string patient) {
  Doctor* doc = GetAvailableDoctor(time);
  if (doc == nullptr) {
    return;
  }

  Appointment apt = {patient, doc, time};
  doc->AddAppointment(time);
  appointments_.push_back(apt);
}
void Hospital::RemoveAppointment(TimeSlot time, std::string patient) {
  for (auto it = appointments_.begin(); it != appointments_.end(); ++it) {
    Appointment& apt = *it;
    if (apt.timeslot == time && apt.patient == patient) {
      apt.doctor->RemoveAppointment(time);
      appointments_.erase(it);
      return;
    }
  }
}
